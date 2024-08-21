/*
** EPITECH PROJECT, 2024
** sources/ftsh/display_prompt.c
** File description:
** Display shell's prompt
** Author: @lszsrd
*/

#include <stdio.h>
#include <pwd.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "ftsh/ftsh.h"

void
display_prompt(struct ftsh *shell)
{
    char *user = getpwuid(getuid())->pw_name;
    char *home = getenv("HOME");
    char *path = NULL;
    void *path_pointer = NULL;

    if (shell->status != 0) {
        printf("\033[31m%d ", shell->status);
    }
    path = getcwd(path, 0);
    path_pointer = path;
    if (path != NULL && home != NULL) {
        if (strncmp(path, home, strlen(home)) == 0) {
            path = memcpy(&path[strlen(home) - 1], "~/", 2);
        }
    }
    printf("\033[34m%s \033[36m%s \033[0m? ", user, path);
    free(path_pointer);
}
