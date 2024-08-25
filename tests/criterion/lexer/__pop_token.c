/*
** EPITECH PROJECT, 2024
** tests/criterion/lexer/__pop_token.c
** File description:
** Test pop_token function
** Author: @lszsrd
*/

#include <string.h>

#include "../criterion.h"
#include "lexer.h"

Test(pop_token, pop_null)
{
    char *stream = (char *) "";

    pop_token(&stream);
    cr_assert_eq(*stream, '\0');
}

Test(pop_token, pop_newline)
{
    char *stream = (char *) "\n";

    pop_token(&stream);
    cr_assert_eq(*stream, '\n');
}

Test(pop_token, pop_semicolon)
{
    char *stream = (char *) "; cd -";

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, pop_character)
{
    char *stream = (char *) "Hello World";

    pop_token(&stream);
    cr_assert_eq(*stream, 'e');
}

Test(pop_token, pop_append_redirection)
{
    char *stream = (char *) ">> week_logs";

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_redirection_output)
{
    char *stream = (char *) "> logs";

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_redirection_errors)
{
    char *stream = (char *) "2> errors_logs";

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_redirection_input)
{
    char *stream = (char *) "< database";

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_redirection_here_document)
{
    char *stream = (char *) "<< EOF";

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_separator_and)
{
    char *stream = (char *) "&& cd -";

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_separator_or)
{
    char *stream = (char *) "|| exit";

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_separator_pipe)
{
    char *stream = (char *) "| grep 'HOME'";

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}

Test(pop_token, digest_is_parenthesis_left)
{
    char *stream = (char *) "(cd -)";

    pop_token(&stream);
    cr_assert_eq(*stream, 'c');
}

Test(pop_token, digest_is_parenthesis_right)
{
    char *stream = (char *) ") ; ls logs";

    pop_token(&stream);
    cr_assert_eq(*stream, ' ');
}
