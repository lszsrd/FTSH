/*
** EPITECH PROJECT, 2024
** sources/ftsh/main.c
** File description:
** Entry point of the program
** Author: @lszsrd
*/

#include <unistd.h>

#include "ftsh/ftsh.h"

struct ftsh shell = {0};

__attribute__((constructor)) static void
constructor(void)
{
    return;
}

__attribute__((destructor)) static void
destructor(void)
{
    return;
}

__attribute__((noreturn)) int
main(__attribute__((unused)) int argc, const char **argv, const char **envp)
{
    do {
        if (isatty(STDIN_FILENO) == 1) {
            display_prompt(&shell);
        }
        read_stdin(&shell);
    } while (1);
    __builtin_unreachable();
}
