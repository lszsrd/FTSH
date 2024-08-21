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
            struct list *IO;
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
        }
        __ast;
    };
    enum token token;
};

struct ast *
parse_stream(char *stream);
