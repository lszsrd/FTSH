/*
** EPITECH PROJECT, 2024
** include/ftsh.h
** File description:
** Define ftsh's structure and function prototypes
** Author: @lszsrd
*/

#pragma once

#include "parser.h"

struct ftsh {
    struct AST *ast;
    unsigned char status;
};

__attribute__((nonnull(1))) void display_prompt(struct ftsh *);
__attribute__((nonnull(1))) char *read_stdin(struct ftsh *);
__attribute__((nonnull(1))) struct AST *parse_stream(char *);
__attribute__((nonnull(1))) void clear_ast(struct AST *);

void display_ast(struct AST *);
