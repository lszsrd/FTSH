/*
** EPITECH PROJECT, 2024
** libraries/list/get_node.c
** File description:
** Get a node from a list
** Author: @lszsrd
*/

#include <string.h>

#include "libraries/list.h"

struct list *
get_node(struct list *ref, const void *data)
{
    if (data == NULL) {
        return (NULL);
    }
    while (ref != NULL) {
        if (strcmp(data, ref->data) == 0) {
            return (ref);
        }
        ref = ref->next;
    }
    return (NULL);
}
