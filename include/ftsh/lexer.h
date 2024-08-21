/*
** EPITECH PROJECT, 2024
** include/ftsh/lexer.h
** File description:
** Define lexer's macros, enums and function prototypes
** Author: @lszsrd
*/

#pragma once

#define REDIRECTION_CHARSETS ">>", ">", "2>", "2>&", "<", "<<"
#define IO_CHARSETS "&&", "||", "|"
#define PARENTHESIS_CHARSETS "(", ")"

enum token {
    CHARACTER, WORD, IO, SEPARATOR, PARENTHESIS, SEMICOLON, EOS
};

enum IO {
    APPEND, OUTPUT, ERRORS, OUTPUTS, INPUT, HERE_DOCUMENT
};

enum separator {
    AND, OR, PIPE
};
