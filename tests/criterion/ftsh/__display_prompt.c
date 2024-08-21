/*
** EPITECH PROJECT, 2024
** tests/criterion/ftsh/__display_prompt.c
** File description:
** Test display_prompt function
** Author: @lszsrd
*/

#include "../criterion.h"
#include "ftsh/ftsh.h"

static void
redirect_stdout(void)
{
    cr_redirect_stdout();
}

Test(read_stdin, standard_output_is_not_null, .init = redirect_stdout)
{
    struct ftsh shell = {0};

    display_prompt(&shell);
    fflush(stdout);
    cr_assert_stdout_neq_str("");
}

Test(read_stdin, exit_status_is_not_zero, .init = redirect_stdout)
{
    struct ftsh shell = {0};

    shell.status = 42;
    display_prompt(&shell);
    fflush(stdout);
    cr_assert_stdout_neq_str("");
}
