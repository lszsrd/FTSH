/*
** EPITECH PROJECT, 2024
** sources/lexer/pop_token.c
** File description:
** Pop current token from stream
** Author: @lszsrd
*/

#include <string.h>

#include "lexer.h"

void pop_token(char **stream)
{
    enum token token = peek_token(*stream);

    if (**stream == '\0' || **stream == '\n') {
        return;
    }
    if (token == CHARACTER || token == DELIMITER) {
        *stream += sizeof(**stream);
        return;
    }
    *stream += strlen(charsets[token][peek_type(*stream, charsets[token])]);
}
