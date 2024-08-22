/*
** EPITECH PROJECT, 2024
** include/ftsh/parser.h
** File description:
** Define parser's macros, structures and function prototypes
** Author: @lszsrd
*/

#pragma once

#include "ftsh/lexer.h"

struct __redirection_data {
    char *file;
    enum redirection digest;
};

struct ast {
    union {
        struct {
            struct list *redirections;
            char **argv;
            char *binary;
        }
        __command;
        struct {
            struct list *commands;
            enum separator digest;
        }
        __separator;
        struct {
            struct ast *left;
            struct ast *right;
            enum delimiter digest;
        }
        __ast;
    };
    enum token token;
};

struct ast *
parse_stream(char *stream);

__attribute__((nonnull(1))) struct ast *
parse_delimiter(char **stream);

__attribute__((nonnull(1))) struct ast *
parse_separator(char **stream);

__attribute__((nonnull(1))) struct ast *
parse_command(char **stream);
