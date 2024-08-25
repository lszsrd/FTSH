/*
** EPITECH PROJECT, 2024
** sources/lexer/peek_type.c
** File description:
** Peek current token type from stream
** Author: @lszsrd
*/

#include <string.h>

short peek_type(const char *stream, const char **charset)
{
    for (unsigned char type = 0; charset[type] != NULL; type++) {
        if (strncmp(stream, charset[type], strlen(charset[type])) == 0) {
            return (type);
        }
    }
    return (-1);
}
