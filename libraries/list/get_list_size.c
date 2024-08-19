/*
** EPITECH PROJECT, 2024
** libraries/list/get_list_length.c
** File description:
** Get number of nodes in a list
** Author: @lszsrd
*/

#include "libraries/list.h"

size_t
get_list_size(struct list *ref)
{
    size_t nodes_count = 0;

    while (ref != NULL) {
        ref = ref->next;
        nodes_count++;
    }
    return (nodes_count);
}
