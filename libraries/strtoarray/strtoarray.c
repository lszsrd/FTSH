/*
** EPITECH PROJECT, 2024
** libraries/strtoarray/strtoarray.c
** File description:
** Creates a strings array from a string tokenized from a list of separators
** Author: @lszsrd
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*
    STRING: "   Hello   Word!!! "
    SEPARATORS: " "
 */

size_t
get_words_count(const char *string, const char *separators)
{
    size_t words = 0;

    if (string == NULL || separators == NULL) {
        return (0);
    }
    for (size_t i = 0; string[i] != 0; i++) {
        if (strchr(separators, string[i]) != NULL) {
            continue;
        }
        if (strchr(separators, string[i + 1]) != NULL) {
            words++;
        }
    }
    return (words);
}

size_t
get_word_length(const char *string, const char *separator, size_t string_index)
{
    size_t word_length = 0;

    while (strchr(separator, string[string_index + word_length]) == NULL) {
        word_length++;
    }
    return (word_length);
}

char **strtoarray(const char *string, const char *separator)
{
    char **strarray = NULL;
    size_t words_count = get_words_count(string, separator);
    size_t current_index = 0;
    size_t word_length = 0;

    if (words_count != 0) {
        strarray = calloc(words_count + 1, sizeof(char *));
    }
    if (strarray == NULL) {
        return (NULL);
    }
    for (size_t current_word = 0; current_word < words_count; current_word++) {
        current_index += word_length;
        while (strchr(separator, string[current_index]) != NULL) {
            current_index++;
        }
        word_length = get_word_length(string, separator, current_index);
        strarray[current_word] = strndup(&string[current_index], word_length);
    }
    return (strarray);
}
