/*
** EPITECH PROJECT, 2024
** tests/criterion/ftsh/__read_stdin.c
** File description:
** Test read_stdin function
** Author: @lszsrd
*/

#include <unistd.h>
#include <errno.h>

#include "../criterion.h"
#include "ftsh/ftsh.h"

Test(read_stdin, standard_input_is_closed)
{
    struct ftsh shell = {0};

    fclose(stdin);
    cr_assert_eq(read_stdin(&shell), NULL);
}

Test(read_stdin, data_is_sent_to_standard_input)
{
    struct ftsh shell = {0};

    if (freopen("tests/criterion/ftsh/__read_stdin.c", "r", stdin) == NULL) {
        cr_assert_eq(1, 0, "Couldn't re-open standard input: %s\n", strerror(errno));
    }
    cr_assert_str_eq(read_stdin(&shell), "/*\n");
}
