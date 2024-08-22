/*
** EPITECH PROJECT, 2024
** sources/lexer/peek_token.c
** File description:
** Peek current token type in parser's stream
** Author: @lszsrd
*/

#include "ftsh/lexer.h"

const char **charsets[] =
{
    (const char *[]) { REDIRECTION_CHARSETS, (void *) 0 },
    (const char *[]) { SEPARATOR_CHARSETS, (void *) 0 },
    (const char *[]) { DELIMITER_CHARSETS, (void *) 0 },
    (void *) 0
};

enum token
peek_token(const char *stream)
{
    if (*stream == '\0' || *stream == '\n') {
        return (NEWLINE);
    }
    for (enum token token = 0; charsets[token] != (void *) 0; token++) {
        if (digest_token(stream, charsets[token]) != -1) {
            return (REDIRECTION + token);
        }
    }
    return (CHARACTER);
}
