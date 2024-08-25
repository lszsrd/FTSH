/*
** EPITECH PROJECT, 2024
** sources/utils/display_ast.c
** File description:
** Display AST's nodes
** Author: @lszsrd
*/

#include <stdio.h>

#include "ftsh.h"
#include "lexer.h"
#include "parser.h"

static void
display_redirection(struct list *head)
{
    struct IO *IO;

    while (head != NULL) {
        IO = (struct IO *) head->data;
        printf("+--- REDIRECTION (%p) ---+\n", (void *) head);
        printf("| TYPE: %s\n", charsets[REDIRECTION][IO->IO]);
        printf("| FILE: %s\n", IO->filename);
        printf("| NEXT: %p\n", (void *) head->next);
        printf("+-----/\n");
        head = head->next;
    }
}

static void
display_command(struct AST *ast)
{
    if (ast == NULL) {
        return;
    }
    printf("+--- COMMAND (%p) ---+\n", (void *) ast);
    printf("| COMMAND: ");
    for (int i = 0; ast->argv[1][i] != NULL; i++) {
        printf("%s ", ast->argv[1][i]);
    }
    printf("\n| REDIRECTIONS: %p\n", (void *) ast->IO);
    printf("+-----/\n");
    display_redirection(ast->IO);
}

static void
display_delimiter_or_separator(struct AST *ast)
{
    if (ast == NULL) {
        return;
    }
    printf("+--- %s (%p) ---+\n", ast->token == DELIMITER ?
        "DELIMITER" : "SEPARATOR", (void *) ast);
    printf("| TYPE: %s\n", charsets[ast->token][ast->type]);
    printf("| LEFT: %p\n", (void *) ast->left);
    printf("| RIGHT: %p\n", (void *) ast->right);
    printf("+-----/\n");
    display_ast(ast->left);
    display_ast(ast->right);
}

void
display_ast(struct AST *ast)
{
    if (ast == NULL) {
        return;
    }
    if (ast->token == DELIMITER || ast->token == SEPARATOR) {
        display_delimiter_or_separator(ast);
    } else {
        display_command(ast);
    }
}
