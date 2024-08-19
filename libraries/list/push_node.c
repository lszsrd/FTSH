/*
** EPITECH PROJECT, 2024
** libraries/list/push_node.c
** File description:
** Push a node to a list
** Author: @lszsrd
*/

#include <stdlib.h>

#include "libraries/list.h"

static unsigned char
populate_new_node(struct list **node, void *data)
{
    *node = calloc(1, sizeof(struct list));
    if ((*node) == NULL) {
        return (0);
    }
    (*node)->data = data;
    return (1);
}

unsigned char
push_node(struct list **ref, void *data)
{
    struct list *penultimate = *ref;

    if ((*ref) == NULL) {
        return (populate_new_node(ref, data));
    }
    while (penultimate->next != NULL) {
        penultimate = penultimate->next;
    }
    return (populate_new_node(&penultimate->next, data));
}
