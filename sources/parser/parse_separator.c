/*
** EPITECH PROJECT, 2024
** sources/parser/parse_separator.c
** File description:
** Parse stream to a separator AST node
** Author: @lszsrd
*/

#include <stdlib.h>

#include "parser.h"

static void
parse_sub_commands(char **stream, struct AST *separator, struct AST *command)
{
    push_list(&separator->commands_list, command);
    if (peek_type(*stream, charsets[SEPARATOR]) == separator->separator) {
        pop_token(stream);
        parse_sub_commands(stream, separator, parse_command(stream));
    }
}

struct AST *
parse_separator(char **stream, char first_separator)
{
    struct AST *command = parse_command(stream);
    struct AST *separator;

    if (peek_token(*stream) != SEPARATOR) {
        return (command);
    }
    separator = calloc(1, sizeof(*separator));
    if (separator == NULL) {
        return (command);
    }
    separator->token = SEPARATOR;
    separator->separator = peek_type(*stream, charsets[SEPARATOR]);
    separator->first_separator = first_separator;
    parse_sub_commands(stream, separator, command);
    if (peek_token(*stream) == SEPARATOR) {
        separator->next_separator = parse_separator(stream, 1);
    }
    return (separator);
}
