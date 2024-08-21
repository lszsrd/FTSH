/*
** EPITECH PROJECT, 2024
** tests/criterion/lexer/__pop_token.c
** File description:
** Test pop_token function
** Author: @lszsrd
*/

#include <string.h>

#include "../criterion.h"
#include "ftsh/lexer.h"

Test(pop_token, pop_null)
{
    char *stream = NULL;

    pop_token(&stream);
    cr_assert_eq(stream, NULL);
}

Test(pop_token, pop_newline)
{
    char *stream = strdup("\n");

    pop_token(&stream);
    cr_assert_eq(*stream, '\n');
}

Test(pop_token, pop_character)
{
    char *stream = strdup("Hello World");

    pop_token(&stream);
    cr_assert_eq(*stream, 'e');
}

Test(pop_token, pop_append_redirection)
{
    char *stream = strdup(">> week_logs");

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_redirection_output)
{
    char *stream = strdup("> logs");

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_redirection_errors)
{
    char *stream = strdup("2> errors_logs");

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_redirection_outputs)
{
    char *stream = strdup("2>&1 all_logs");

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_redirection_input)
{
    char *stream = strdup("< database");

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_redirection_here_document)
{
    char *stream = strdup("<< EOF");

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_separator_and)
{
    char *stream = strdup("&& cd -");

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_separator_or)
{
    char *stream = strdup("|| exit");

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_separator_pipe)
{
    char *stream = strdup("| grep 'HOME'");

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_parenthesis_left)
{
    char *stream = strdup("(cd -)");

    pop_token(&stream);
    cr_assert_eq(*stream, 'c');
}

Test(pop_token, digest_is_parenthesis_right)
{
    char *stream = strdup(") ; ls logs");

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}
