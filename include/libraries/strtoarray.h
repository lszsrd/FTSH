/*
** EPITECH PROJECT, 2024
** include/libraries/strtoarray.h
** File description:
** Define strtoarray library's function prototypes
** Author: @lszsrd
*/

#pragma once

#include <stddef.h>

char **strtoarray(const char *, const char *);
void clear_strarray(char **);
size_t get_strarray_size(const char **);
