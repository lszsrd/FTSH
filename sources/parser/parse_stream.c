/*
** EPITECH PROJECT, 2024
** sources/parser/parse_stream.c
** File description:
** Parse standard input data to an abstract syntax tree
** Author: @lszsrd
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parser.h"

struct AST *
parse_stream(char *stream)
{
    void *stream_pointer = stream;
    struct AST *ast;

    if (stream == NULL) {
        return (NULL);
    }
    ast = parse_delimiter(&stream);
    free(stream_pointer);
    return (ast);
}
