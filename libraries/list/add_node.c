/*
** EPITECH PROJECT, 2024
** libraries/list/add_node.c
** File description:
** Add a node to a list
** Author: @lszsrd
*/

#include <stdlib.h>

#include "libraries/list.h"

unsigned char
add_node(struct list **ref, void *data)
{
    struct list *node = NULL;

    node = calloc(1, sizeof(struct list));
    if (node == NULL) {
        return (0);
    }
    node->data = data;
    node->next = *ref;
    *ref = node;
    return (1);
}
