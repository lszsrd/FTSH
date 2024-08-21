/*
** EPITECH PROJECT, 2024
** tests/criterion/lexer/__peek_token.c
** File description:
** Test peek_token function
** Author: @lszsrd
*/

#include "../criterion.h"
#include "ftsh/lexer.h"

extern const char **charsets[];

Test(peek_token, digest_is_invalid)
{
    cr_assert_eq(digest_token("Hello World", charsets[0]), -1);
}

Test(peek_token, digest_is_redirection_append)
{
    cr_assert_eq(digest_token(">> week_logs", charsets[0]), APPEND);
}

Test(peek_token, digest_is_redirection_output)
{
    cr_assert_eq(digest_token("> logs", charsets[0]), OUTPUT);
}

Test(peek_token, digest_is_redirection_errors)
{
    cr_assert_eq(digest_token("2> errors_logs", charsets[0]), ERRORS);
}

Test(peek_token, digest_is_redirection_outputs)
{
    cr_assert_eq(digest_token("2>&1 all_logs", charsets[0]), OUTPUTS);
}

Test(peek_token, digest_is_redirection_input)
{
    cr_assert_eq(digest_token("< database", charsets[0]), INPUT);
}

Test(peek_token, digest_is_redirection_here_document)
{
    cr_assert_eq(digest_token("<< EOF", charsets[0]), HERE_DOCUMENT);
}

Test(peek_token, digest_is_separator_and)
{
    cr_assert_eq(digest_token("&& cd -", charsets[1]), AND);
}

Test(peek_token, digest_is_separator_or)
{
    cr_assert_eq(digest_token("|| exit", charsets[1]), OR);
}

Test(peek_token, digest_is_separator_pipe)
{
    cr_assert_eq(digest_token("| grep 'HOME'", charsets[1]), PIPE);
}

Test(peek_token, digest_is_parenthesis_left)
{
    cr_assert_eq(digest_token("(cd -)", charsets[2]), OPEN);
}

Test(peek_token, digest_is_parenthesis_right)
{
    cr_assert_eq(digest_token(") ; ls logs", charsets[2]), CLOSE);
}
