/*
** EPITECH PROJECT, 2024
** include/libraries/list.h
** File description:
** Define list library's structure and function prototypes
** Author: @lszsrd
*/

#pragma once

#include <stddef.h>

struct list {
    void *data;
    struct list *next;
};

unsigned char
add_node(struct list **ref, void *data);

unsigned char
push_node(struct list **ref, void *data);

unsigned char
pop_node(struct list **ref, struct list *node, void (*cleanup) (void *));

void
free_list(struct list **ref, void (*cleanup) (void *));

struct list *
get_node(struct list *ref, const void *data);

size_t
get_list_size(struct list *ref);
