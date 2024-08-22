/*
** EPITECH PROJECT, 2024
** sources/parser/parse_command.c
** File description:
** Parse standard input to a command abstract syntax tree node
** Author: @lszsrd
*/

#include <stdlib.h>
#include <string.h>

#include "ftsh/parser.h"
#include "libraries/list.h"

extern const char **charsets[];

static size_t
parse_character(char **stream)
{
    size_t word_length = 0;

    for (; peek_token(*stream) == CHARACTER; pop_token(stream)) {
        if (word_length == 0 && (**stream == ' ' || **stream == '\t')) {
            continue;
        }
        word_length++;
    }
    return (word_length);
}

static void
parse_redirection(char **stream, struct list **ref)
{
    struct __redirection_data *__redirection = NULL;
    size_t word_length = 0;

    if (peek_token(*stream) != REDIRECTION) {
        return;
    }
    __redirection = calloc(1, sizeof(struct __redirection_data));
    if (__redirection == NULL) {
        return;
    }
    __redirection->digest = digest_token(*stream, charsets[0]);
    pop_token(stream);
    word_length = parse_character(stream);
    if (word_length != 0) {
        __redirection->file = strndup(*stream - word_length, word_length);
    }
    push_node(ref, __redirection);
    parse_redirection(stream, ref);
}

struct ast *
parse_command(char **stream)
{
    size_t command_length = parse_character(stream);
    struct ast *node = NULL;

    if (command_length != 0) {
        node = calloc(1, sizeof(struct ast));
    }
    if (node == NULL) {
        return (NULL);
    }
    node->token = COMMAND;
    node->__command.binary = strndup(*stream - command_length, command_length);
    parse_redirection(stream, &node->__command.redirections);
    return (node);
}
