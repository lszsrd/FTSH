/*
** EPITECH PROJECT, 2024
** sources/parser/parse_stream.c
** File description:
** Parse standard input to an abstract syntax tree
** Author: @lszsrd
*/

#include <stdlib.h>

#include "ftsh/parser.h"

struct ast *
parse_stream(char *stream)
{
    struct ast *ast = NULL;
    void *stream_pointer = stream;

    if (stream == NULL) {
        return (NULL);
    }
    free(stream_pointer);
    return (ast);
}
