/*
** EPITECH PROJECT, 2024
** include/criterion/criterion.h
** File description:
** Define criterion's library path based on OS
** Author: @lszsrd
*/

#pragma once

#ifdef __APPLE__
    #include </opt/homebrew/include/criterion/criterion.h>
    #include </opt/homebrew/include/criterion/redirect.h>
#else
    #include <criterion/criterion.h>
    #include <criterion/redirect.h>
#endif
