/*
** EPITECH PROJECT, 2024
** sources/parser/parse_delimiter.c
** File description:
** Parse stream to a delimiter AST node
** Author: @lszsrd
*/

#include <stdlib.h>

#include "lexer.h"
#include "parser.h"

extern const char **charsets[];

// TODO: Handle parenthesis parsing
struct AST *
parse_delimiter(char **stream)
{
    struct AST *separator = parse_separator(stream);
    struct AST *delimiter;

    if (peek_token(*stream) != DELIMITER) {
        return (separator);
    }
    delimiter = calloc(1, sizeof(*delimiter));
    if (delimiter == NULL) {
        return (separator);
    }
    delimiter->token = DELIMITER;
    delimiter->type = peek_type(*stream, charsets[DELIMITER]);
    delimiter->left = separator;
    pop_token(stream);
    delimiter->right = parse_delimiter(stream);
    return (delimiter);
}
