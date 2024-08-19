/*
** EPITECH PROJECT, 2024
** sources/ftsh/display_prompt.c
** File description:
** Display shell's prompt
** Author: @lszsrd
*/

#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>

#include "ftsh/ftsh.h"

void
display_prompt(struct ftsh *shell)
{
    char *user = getpwuid(getuid())->pw_name;
    char *path = NULL;

    path = getcwd(path, 0);
    if (shell->status != 0) {
        printf("(\033[31m%d\033[0m) ", shell->status);
    }
    printf("\033[34m%s \033[0m- \033[36m%s \033[0m? ", user, path);
    free(path);
}
