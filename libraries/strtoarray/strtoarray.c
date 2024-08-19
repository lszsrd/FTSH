/*
** EPITECH PROJECT, 2024
** libraries/strtoarray/strtoarray.c
** File description:
** Creates a strings array from a string tokenized from a list of separators
** Author: @lszsrd
*/

#include <stdlib.h>
#include <string.h>

static ssize_t
get_words_count(const char *str, const char *separators)
{
    ssize_t words_count = 0;

    if (str == NULL || *str == '\0' || separators == NULL) {
        return (-1);
    }
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (strchr(separators, str[i]) == NULL
            && strchr(separators, str[i + 1]) != NULL) {
            words_count++;
        }
    }
    return (words_count);
}

static char *
tokenize_string(const char *string, const char *separators, size_t *index)
{
    size_t buffer_length = 0;
    char *buffer = NULL;

    while (strchr(separators, (string + (*index))[buffer_length]) == NULL) {
        buffer_length++;
    }
    if (buffer_length == 0) {
        (*index)++;
        return (tokenize_string(string, separators, index));
    }
    buffer = strndup(string + (*index), buffer_length);
    while (strchr(separators, (string + (*index))[buffer_length]) != NULL) {
        (*index)++;
    }
    *index += buffer_length;
    return (buffer);
}

char **
strtoarray(const char *string, const char *separators)
{
    ssize_t words_count = get_words_count(string, separators);
    char **strarray = NULL;
    size_t index = 0;

    if (words_count == -1) {
        return (NULL);
    }
    strarray = calloc(words_count + 1, sizeof(char *));
    if (strarray == NULL) {
        return (NULL);
    }
    for (ssize_t i = 0; i < words_count; i++) {
        strarray[i] = tokenize_string(string, separators, &index);
    }
    return (strarray);
}
