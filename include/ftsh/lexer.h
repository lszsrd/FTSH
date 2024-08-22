/*
** EPITECH PROJECT, 2024
** include/ftsh/lexer.h
** File description:
** Define lexer's macros, enums and function prototypes
** Author: @lszsrd
*/

#pragma once

#define REDIRECTION_CHARSETS ">>", ">", "2>&1", "2>", "<<", "<"
#define SEPARATOR_CHARSETS "&&", "||", "|"
#define DELIMITER_CHARSETS ";", "(", ")"

enum redirection {
    APPEND, OUTPUT, OUTPUTS, ERRORS, HERE_DOCUMENT, INPUT
};

enum separator {
    AND, OR, PIPE
};

enum delimiter {
    SEMICOLON, OPEN, CLOSE
};

enum token {
    CHARACTER, COMMAND, REDIRECTION, SEPARATOR, DELIMITER, NEWLINE
};

__attribute__((nonnull(1))) enum token
peek_token(const char *stream);

__attribute__((nonnull(1, 2))) short
digest_token(const char *stream, const char **charset);

__attribute__((nonnull(1))) void
pop_token(char **stream);
