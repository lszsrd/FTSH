/*
** EPITECH PROJECT, 2024
** libraries/list/clear_list.c
** File description:
** Release a list's allocated memory
** Author: @lszsrd
*/

#include <stdlib.h>

#include "libraries/list.h"

void
free_list(struct list **ref, void (*function) (void *ptr))
{
    struct list *node = *ref;
    struct list *temp = NULL;

    if (function == NULL) {
        return;
    }
    while (node != NULL) {
        temp = node;
        node = node->next;
        function(temp->data);
        free(temp->data);
        free(temp);
    }
    *ref = NULL;
}
