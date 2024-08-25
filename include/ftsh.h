/*
** EPITECH PROJECT, 2024
** include/ftsh.h
** File description:
** Define ftsh's structure and function prototypes
** Author: @lszsrd
*/

#pragma once

struct AST;

struct ftsh {
    struct AST *ast;
    unsigned char status;
};

__attribute__((nonnull(1))) void display_prompt(struct ftsh *);
char *read_stdin(struct ftsh *);
struct AST *parse_stream(char *);
