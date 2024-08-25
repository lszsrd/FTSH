/*
** EPITECH PROJECT, 2024
** sources/parser/parse_delimiter.c
** File description:
** Parse stream to a delimiter AST node
** Author: @lszsrd
*/

#include <stdlib.h>

#include "parser.h"

extern const char **charsets[];

// TODO: Handle proper parenthesis handler
struct AST *
parse_delimiter(char **stream)
{
    struct AST *delimiter;
    struct AST *separator = parse_separator(stream, 0);

    if (peek_token(*stream) != DELIMITER) {
        return (separator);
    }
    delimiter = calloc(1, sizeof(*delimiter));
    if (delimiter == NULL) {
        return (separator);
    }
    delimiter->token = DELIMITER;
    delimiter->delimiter = peek_type(*stream, charsets[DELIMITER]);
    delimiter->left_operand = separator;
    pop_token(stream);
    delimiter->right_operand = parse_delimiter(stream);
    return (delimiter);
}
