/*
** EPITECH PROJECT, 2024
** tests/criterion/ftsh/__read_stdin.c
** File description:
** Test read_stdin function
** Author: @lszsrd
*/

#include "../criterion.h"
#include "ftsh/ftsh.h"

Test(read_stdin, standard_input_is_closed)
{
    struct ftsh shell = {0};

    fclose(stdin);
    cr_assert_eq(read_stdin(&shell), NULL);
}
