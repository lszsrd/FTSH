/*
** EPITECH PROJECT, 2024
** include/libraries/list.h
** File description:
** Define list's structure and function prototypes
** Author: @lszsrd
*/

#pragma once

struct list {
    void *data;
    struct list *next;
};

void push_list(struct list **, void *data);
__attribute__((nonnull(2))) void clear_list(struct list **, void (*)(void *));
