/*
** EPITECH PROJECT, 2024
** sources/ftsh/main.c
** File description:
** Entry point of the program
** Author: @lszsrd
*/

#include <stdlib.h>
#include <unistd.h>

#include "ftsh.h"

struct ftsh shell = {0};

__attribute__((constructor)) static void
constructor(void)
{
    return;
}

// TODO: Add AST expansion (grammar check and aliases replacement)
__attribute__((noreturn))
int main(__attribute__((unused)) int argc, const char **argv)
{
    while (1) {
        if (isatty(STDIN_FILENO) == 1) {
            display_prompt(&shell);
        }
        shell.ast = parse_stream(read_stdin(&shell));
        clear_ast(shell.ast);
    }
    __builtin_unreachable();
}

__attribute__((destructor)) static void
destructor(void)
{
    return;
}
