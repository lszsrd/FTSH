/*
** EPITECH PROJECT, 2024
** tests/criterion/lexer/__peek_token.c
** File description:
** Test peek_token function
** Author: @lszsrd
*/

#include "../criterion.h"
#include "lexer.h"

extern const char **charsets[];

Test(peek_token, type_is_invalid)
{
    cr_assert_eq(peek_type("Hello World", charsets[REDIRECTION]), -1);
}

Test(peek_token, type_is_redirection_append)
{
    cr_assert_eq(peek_type(">> week_logs", charsets[REDIRECTION]), STDOUT_APPEND);
}

Test(peek_token, type_is_redirection_output)
{
    cr_assert_eq(peek_type("> logs", charsets[REDIRECTION]), STDOUT);
}

Test(peek_token, type_is_redirection_output_error_append)
{
    cr_assert_eq(peek_type("&>> logs", charsets[REDIRECTION]), STDOUT_STDERR_APPEND);
}

Test(peek_token, type_is_redirection_errors)
{
    cr_assert_eq(peek_type("&> errors_logs", charsets[REDIRECTION]), STDOUT_STDERR);
}

Test(peek_token, type_is_redirection_stderr_append)
{
    cr_assert_eq(peek_type("2>> all_logs", charsets[REDIRECTION]), STDERR_APPEND);
}

Test(peek_token, type_is_redirection_stderr)
{
    cr_assert_eq(peek_type("2> all_logs", charsets[REDIRECTION]), STDERR);
}

Test(peek_token, type_is_redirection_input)
{
    cr_assert_eq(peek_type("< database", charsets[REDIRECTION]), INPUT);
}

Test(peek_token, type_is_redirection_here_document)
{
    cr_assert_eq(peek_type("<< EOF", charsets[REDIRECTION]), HERE_DOCUMENT);
}

Test(peek_token, type_is_separator_and)
{
    cr_assert_eq(peek_type("&& cd -", charsets[SEPARATOR]), AND);
}

Test(peek_token, type_is_separator_or)
{
    cr_assert_eq(peek_type("|| exit", charsets[SEPARATOR]), OR);
}

Test(peek_token, type_is_separator_pipe)
{
    cr_assert_eq(peek_type("| grep 'HOME'", charsets[SEPARATOR]), PIPE);
}

Test(peek_token, type_is_semicolon)
{
    cr_assert_eq(peek_type(";cd -)", charsets[DELIMITER]), SEMICOLON);
}

Test(peek_token, type_is_parenthesis_left)
{
    cr_assert_eq(peek_type("(cd -)", charsets[DELIMITER]), OPENING_PARENTHESIS);
}

Test(peek_token, type_is_parenthesis_right)
{
    cr_assert_eq(peek_type(") ; ls logs", charsets[DELIMITER]), CLOSING_PARENTHESIS);
}
