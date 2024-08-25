/*
** EPITECH PROJECT, 2024
** sources/parser/parse_separator.c
** File description:
** Parse stream to a separator AST node
** Author: @lszsrd
*/

#include <stdlib.h>

#include "lexer.h"
#include "parser.h"

struct AST *
parse_separator(char **stream)
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
    separator->type = peek_type(*stream, charsets[SEPARATOR]);
    separator->left = command;
    pop_token(stream);
    separator->right = parse_separator(stream);
    return (separator);
}
