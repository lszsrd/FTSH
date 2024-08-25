/*
** EPITECH PROJECT, 2024
** sources/parser/parse_command.c
** File description:
** Parse stream to a command AST node
** Author: @lszsrd
*/

#include <stdlib.h>
#include <string.h>

#include "parser.h"

static unsigned short
parse_characters(char **stream)
{
    unsigned short word_length = 0;

    for (; peek_token(*stream) == CHARACTER; pop_token(stream)) {
        if (word_length == 0 && (**stream == ' ' || **stream == '\t')) {
            continue;
        }
        word_length++;
    }
    return (word_length);
}

static void
parse_redirection(char **stream, struct list **head, int redirection)
{
    unsigned short filename_length;
    struct IO *node;

    if (peek_token(*stream) != REDIRECTION) {
        return;
    }
    pop_token(stream);
    filename_length = parse_characters(stream);
    if (filename_length == 0) {
        return;
    }
    node = calloc(1, sizeof(*node));
    if (node == NULL) {
        return;
    }
    node->filename_path = strndup(*stream - filename_length, filename_length);
    node->redirection = redirection;
    push_list(head, node);
    parse_redirection(stream, head, peek_type(*stream, charsets[REDIRECTION]));
}

struct AST *
parse_command(char **stream)
{
    unsigned short length = parse_characters(stream);
    struct AST *command;

    if (length == 0) {
        return (NULL);
    }
    command = calloc(1, sizeof(*command));
    if (command == NULL) {
        return (NULL);
    }
    command->binary_path = strndup(*stream - length, length);
    command->token = COMMAND;
    parse_redirection(stream, &command->redirections, peek_type(
        *stream, charsets[REDIRECTION])
    );
    return (command);
}
