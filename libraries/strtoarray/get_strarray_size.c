/*
** EPITECH PROJECT, 2024
** libraries/strtoarray/get_strarray_size.c
** File description:
** Get number of strings in a strings array
** Author: @lszsrd
*/

#include <stddef.h>

size_t
get_strarray_size(const char **strarray)
{
    size_t array_size = 0;

    if (strarray == NULL) {
        return (0);
    }
    for (int i = 0; strarray[i] != NULL; i++) {
        array_size++;
    }
    return (array_size);
}
