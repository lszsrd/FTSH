/*
** EPITECH PROJECT, 2024
** libraries/list/clear_list.c
** File description:
** Free a list's allocated memory
** Author: @lszsrd
*/

#include <stdlib.h>

#include "libraries/list.h"

void
clear_list(struct list **head, void (*clear)(void *))
{
    struct list *buffer;

    while (*head != NULL) {
        buffer = *head;
        *head = (*head)->next;
        clear(buffer->data);
        free(buffer->data);
        free(buffer);
    }
}
