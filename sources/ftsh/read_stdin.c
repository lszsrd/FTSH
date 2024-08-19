/*
** EPITECH PROJECT, 2024
** sources/ftsh/read_stdin.c
** File description:
** Read standard input
** Author: @lszsrd
*/

#include <stdio.h>
#include <stdlib.h>

#include "ftsh/ftsh.h"

// TODO: Use termios to handle proper line edition
char *
read_stdin(struct ftsh *shell)
{
    char *buffer = NULL;
    size_t buffer_size = 0;

    if (getline(&buffer, &buffer_size, stdin) == EOF) {
        free(buffer);
        exit(shell->status);
    }
    return (buffer);
}
