/*
** EPITECH PROJECT, 2024
** include/lexer.h
** File description:
** Define lexer's enums and function prototypes
** Author: @lszsrd
*/

#pragma once

extern const char **charsets[];

enum delimiter {
    SEMICOLON,
    OPENING_PARENTHESIS,
    CLOSING_PARENTHESIS,
};

enum separator {
    AND,
    OR,
    PIPE,
};

enum redirection {
    STDOUT_APPEND,
    STDOUT,
    STDOUT_STDERR_APPEND,
    STDOUT_STDERR,
    STDERR_APPEND,
    STDERR,
    HERE_DOCUMENT,
    INPUT,
};

enum token {
    DELIMITER,
    SEPARATOR,
    REDIRECTION,
    COMMAND,
    CHARACTER,
    NEWLINE,
};

__attribute__((nonnull(1))) enum token peek_token(const char *);
__attribute__((nonnull(1, 2))) short peek_type(const char *, const char **);
__attribute__((nonnull(1))) void pop_token(char **);
