/*
** EPITECH PROJECT, 2024
** sources/ftsh/read_stdin.c
** File description:
** Read data from standard input
** Author: @lszsrd
*/

#include <stdio.h>
#include <stdlib.h>

#include "ftsh.h"

char *
read_stdin(struct ftsh *shell)
{
    char *stream = NULL;
    size_t stream_size = 0;

    if (getline(&stream, &stream_size, stdin) == EOF) {
        free(stream);
        exit(shell->status);
    }
    return (stream);
}
