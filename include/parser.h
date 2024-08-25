/*
** EPITECH PROJECT, 2024
** include/parser.h
** File description:
** Define parser's structures and function prototypes
** Author: @lszsrd
*/

#pragma once

#include "lexer.h"
#include "libraries/list.h"

struct IO {
    enum redirection IO;
    char *filename;
};

struct AST {
    enum token token;
    union {
        struct {
            short type;
            struct AST *left;
            struct AST *right;
        };
        struct {
            struct list *IO;
            char **argv[2];
        };
    };
};

struct AST *parse_stream(char *);

__attribute__((nonnull(1))) struct AST *parse_delimiter(char **);
__attribute__((nonnull(1))) struct AST *parse_separator(char **);
__attribute__((nonnull(1))) struct AST *parse_command(char **);
