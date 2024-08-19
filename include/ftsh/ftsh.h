/*
** EPITECH PROJECT, 2024
** include/ftsh/ftsh.h
** File description:
** Define ftsh's macros, structure and function prototypes
** Author: @lszsrd
*/

#pragma once

#include "libraries/list.h"

#define __ENV 0

struct ftsh {
    char **envp;
    struct list *refs[1];
    unsigned char status;
};
