/*
** EPITECH PROJECT, 2024
** libraries/list/pop_node.c
** File description:
** Delete a node from a list
** Author: @lszsrd
*/

#include <stdlib.h>

#include "libraries/list.h"

unsigned char
pop_node(struct list **ref, struct list *node, void (*cleanup) (void *ptr))
{
    struct list *prev = NULL;

    if (ref == NULL || node == NULL) {
        return (-1);
    }
    for (prev = (*ref); prev != NULL && prev->next != node; prev = prev->next);
    if (prev == NULL) {
        return (-1);
    }
    if (node == *ref) {
        *ref = (*ref)->next;
    } else {
        prev->next = prev->next->next;
    }
    cleanup(node->data);
    free(node->data);
    free(node);
    return (0);
}
