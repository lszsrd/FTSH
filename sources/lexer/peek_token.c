/*
** EPITECH PROJECT, 2024
** sources/lexer/peek_token.c
** File description:
** Peek current token from stream
** Author: @lszsrd
*/

#include "lexer.h"

const char **charsets[] = {
    (const char *[]) { ";", "(", ")", 0 },
    (const char *[]) { "&&", "||", "|", 0 },
    (const char *[]) { ">>", ">", "&>>", "&>", "2>>", "2>", "<<", "<", 0 },
    0
};

enum token peek_token(const char *stream)
{
    if (*stream == '\n') {
        return (NEWLINE);
    }
    for (enum token token = DELIMITER; charsets[token] != 0; token++) {
        if (peek_type(stream, charsets[token]) != -1) {
            return (token);
        }
    }
    return (CHARACTER);
}
