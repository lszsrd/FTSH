/*
** EPITECH PROJECT, 2024
** libraries/list/push_list.c
** File description:
** Push data to a list
** Author: @lszsrd
*/

#include <stdlib.h>

#include "libraries/list.h"

static void
allocate_node(struct list **ref, void *data)
{
    *ref = calloc(1, sizeof(struct list));
    if (*ref != NULL) {
        (*ref)->data = data;
    }
}

void
push_list(struct list **head, void *data)
{
    struct list *last;

    if (*head == NULL) {
        allocate_node(head, data);
        return;
    }
    for (last = *head; last->next != NULL; last = last->next);
    allocate_node(&last->next, data);
}
