/*
** EPITECH PROJECT, 2024
** sources/lexer/digest_token.c
** File description:
** Peek current token digest in parser's stream
** Author: @lszsrd
*/

#include <string.h>

short
digest_token(const char *stream, const char **charset)
{
    for (unsigned char digest = 0; charset[digest] != (void *) 0; digest++) {
        if (strncmp(charset[digest], stream, strlen(charset[digest])) == 0) {
            return (digest);
        }
    }
    return (-1);
}
