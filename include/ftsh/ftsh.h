/*
** EPITECH PROJECT, 2024
** include/ftsh/ftsh.h
** File description:
** Define ftsh's macros, structure and function prototypes
** Author: @lszsrd
*/

#pragma once

struct ast;

struct ftsh {
    struct ast *ast;
    unsigned char status;
};

__attribute__((nonnull(1))) void
display_prompt(struct ftsh *shell);

__attribute__((nonnull(1))) char *
read_stdin(struct ftsh *shell);
