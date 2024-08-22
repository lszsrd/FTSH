/*
** EPITECH PROJECT, 2024
** sources/parser/parse_separator.c
** File description:
** Parse standard input to a separator abstract syntax tree node
** Author: @lszsrd
*/

#include <stdlib.h>

#include "libraries/list.h"
#include "ftsh/parser.h"

extern const char **charsets[];

struct ast *
parse_separator(char **stream)
{
    struct ast *node = NULL;
    struct ast *__command = parse_command(stream);
    enum token token = peek_token(*stream);

    if (token != SEPARATOR) {
        return (__command);
    }
    node = calloc(1, sizeof(struct ast));
    if (node == NULL) {
        return (__command);
    }
    node->token = token;
    node->__separator.digest = digest_token(*stream, charsets[1]);
    push_node(&node->__separator.commands, __command);
    do {
        pop_token(stream);
        push_node(&node->__separator.commands, parse_command(stream));
    } while (digest_token(*stream, charsets[1]) == node->__separator.digest);
    return (node);
}
