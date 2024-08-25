/*
** EPITECH PROJECT, 2024
** libraries/strtoarray/clear_strarray.c
** File description:
** Release strarray's allocated memory
** Author: @lszsrd
*/

#include <stdlib.h>

void
clear_strarray(char **strarray)
{
    if (strarray == NULL) {
        return;
    }
    for (size_t i = 0; strarray[i] != NULL; i++) {
        free(strarray[i]);
    }
    free(strarray);
}
