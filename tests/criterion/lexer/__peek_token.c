/*
** EPITECH PROJECT, 2024
** tests/criterion/lexer/__peek_token.c
** File description:
** Test peek_token function
** Author: @lszsrd
*/

#include "../criterion.h"
#include "lexer.h"

Test(peek_token, token_is_a_character)
{
    cr_assert_eq(peek_token("Hello World"), CHARACTER);
}

Test(peek_token, token_is_a_redirection)
{
    cr_assert_eq(peek_token(">> logs"), REDIRECTION);
}

Test(peek_token, token_is_a_separator)
{
    cr_assert_eq(peek_token("|| cat logs"), SEPARATOR);
}

Test(peek_token, token_is_a_PARENTHESIS)
{
    cr_assert_eq(peek_token(") cd -"), DELIMITER);
}

Test(peek_token, token_is_a_semicolon)
{
    cr_assert_eq(peek_token("; exit"), DELIMITER);
}

Test(peek_token, token_is_a_newline)
{
    cr_assert_eq(peek_token("\n"), NEWLINE);
}
