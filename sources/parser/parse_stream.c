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
    unsigned char not_empty_stream = 0;

    for (size_t i = 0; stream != NULL && stream[i] != '\0'; i++) {
        if (stream[i] != ' ' && stream[i] != '\t') {
            not_empty_stream = 1;
            break;
        }
    }
    if (not_empty_stream == 1) {
        ast = parse_delimiter(&stream);
    }
    free(stream_pointer);
    return (ast);
}
