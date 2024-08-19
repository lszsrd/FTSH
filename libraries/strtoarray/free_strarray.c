/*
** EPITECH PROJECT, 2024
** libraries/strtoarray/free_strarray.c
** File description:
** Release a strings array's allocated memory
** Author: @lszsrd
*/

#include <stdlib.h>

void
free_strarray(char **strarray)
{
    if (strarray == NULL) {
        return;
    }
    for (size_t i = 0; strarray[i] != NULL; i++) {
        free(strarray[i]);
    }
    free(strarray);
}
