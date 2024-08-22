/*
** EPITECH PROJECT, 2024
** sources/parser/parse_delimiter.c
** File description:
** Parse standard input to a delimiter abstract syntax tree node
** Author: @lszsrd
*/

#include <stdlib.h>

#include "ftsh/parser.h"

extern const char **charsets[];

struct ast *
parse_delimiter(char **stream)
{
    struct ast *node = NULL;
    struct ast *__left = parse_separator(stream);
    enum token token = peek_token(*stream);

    if (token == NEWLINE || __left == NULL) {
        return (__left);
    }
    node = calloc(1, sizeof(struct ast));
    if (node == NULL) {
        return (__left);
    }
    node->token = token;
    node->__ast.digest = digest_token(*stream, charsets[2]);
    node->__ast.left = __left;
    pop_token(stream);
    node->__ast.right = parse_delimiter(stream);
    return (node);
}
