/*
** EPITECH PROJECT, 2024
** sources/parser/clear_ast
** File description:
** Free AST's allocated memory
** Author: @lszsrd
*/

#include <stdlib.h>

#include "libraries/list.h"
#include "parser.h"

static void clear_redirections_list(void *node)
{
    struct IO *redirection = node;

    if (redirection == NULL) {
        return;
    }
    free(redirection->filename_path);
}

static void clear_commands_list(void *node)
{
    struct AST *command = node;

    if (command == NULL) {
        return;
    }
    free(command->binary_path);
    clear_list(&command->redirections, clear_redirections_list);
}

void clear_ast(struct AST *ast)
{
    if (ast == NULL) {
        return;
    }
    switch (ast->token) {
        case (DELIMITER):
            clear_ast(ast->left_operand);
            clear_ast(ast->right_operand);
            break;
        case (SEPARATOR):
            clear_list(&ast->commands_list, clear_commands_list);
            clear_ast(ast->next_separator);
            break;
        default:
            clear_commands_list(ast);
    }
    free(ast);
}
