/*
** EPITECH PROJECT, 2024
** sources/lexer/pop_token.c
** File description:
** Pop current token from parser's stream
** Author: @lszsrd
*/

#include <string.h>

#include "ftsh/lexer.h"

extern const char **charsets[];

void
pop_token(char **stream)
{
    enum token token = peek_token(*stream);

    if (token == NEWLINE) {
        return;
    }
    if (token == CHARACTER || token == SEMICOLON) {
        *stream += sizeof(char);
        return;
    }
    *stream += strlen(charsets[token - REDIRECTION]
        [digest_token(*stream, charsets[token - REDIRECTION])]);
}
