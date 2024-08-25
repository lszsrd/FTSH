/*
** EPITECH PROJECT, 2024
** sources/ftsh/clear_ast.c
** File description:
** Free AST's allocated memory
** Author: @lszsrd
*/

#include <stdlib.h>

#include "libraries/list.h"
#include "libraries/strtoarray.h"
#include "parser.h"

static void clear_redirections(void *node)
{
    if (node != NULL) {
        free(((struct IO *) node)->filename);
    }
}

static void clear_command(void *node)
{
    if (node != NULL) {
        free(((struct AST *) node)->argv[0]);
        clear_strarray(((struct AST *) node)->argv[1]);
        clear_list(&((struct AST *) node)->IO, clear_redirections);
    }
}

void clear_ast(struct AST *ast)
{
    if (ast == NULL) {
        return;
    }
    if (ast->token == DELIMITER || ast->token == SEPARATOR) {
        clear_ast(ast->left);
        clear_ast(ast->right);
    } else {
        clear_command(ast);
    }
    free(ast);
}
