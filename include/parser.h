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
    enum redirection redirection : 16;
    char *filename_path;
};

struct AST {
    enum token token;
    union {
        struct {
            enum delimiter delimiter : 16;
            struct AST *left_operand;
            struct AST *right_operand;
        };
        struct {
            enum separator separator : 16;
            unsigned char first_separator;
            struct list *commands_list;
            struct AST *next_separator;
        };
        struct {
            char *binary_path;
            char **command_arguments;
            struct list *redirections;
        };
    };
};

struct AST *parse_stream(char *);

__attribute__((nonnull(1))) struct AST *parse_delimiter(char **);
__attribute__((nonnull(1))) struct AST *parse_separator(char **, char);
__attribute__((nonnull(1))) struct AST *parse_command(char **);

void clear_ast(struct AST *);
