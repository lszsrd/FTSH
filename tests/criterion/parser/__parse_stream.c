/*
** EPITECH PROJECT, 2024
** tests/criterion/parser/__parse_stream.c
** File description:
** Test parse_stream function
** Author: @lszsrd
*/

#include "../criterion.h"
#include "ftsh/parser.h"

Test(parse_stream, stream_is_null)
{
    cr_assert_null(parse_stream(NULL));
}

Test(parse_stream, stream_is_not_null, .disabled = true)
{
    cr_assert_not_null(parse_stream(NULL));
}
