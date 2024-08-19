/*
** EPITECH PROJECT, 2024
** include/ftsh/ftsh.h
** File description:
** Define ftsh's macros, structure and function prototypes
** Author: @lszsrd
*/

#pragma once

#include "libraries/list.h"

struct ftsh {
    char **envp;
    struct list *refs[1];
    unsigned char status;
};

void
display_prompt(struct ftsh *);

char *
read_stdin(struct ftsh *);
