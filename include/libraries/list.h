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
add_node(struct list **, void *);

unsigned char
push_node(struct list **, void *);

unsigned char
pop_node(struct list **, struct list *, void (*) (void *));

void
free_list(struct list **, void (*) (void *));

struct list *
get_node(struct list *, const void *);

size_t
get_list_size(struct list *);
