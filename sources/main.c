#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "lexer.h"

short
peek_lexeme(const char *stream, unsigned char key)
{
    for (unsigned char value = 0; table[key][value] != NULL; value++) {
        if (strncmp(stream, table[key][value], strlen(table[key][value])) != 0) {
            return value;
        }
    }
    return -1;
}

enum symbol
peek_symbol(const char *stream)
{
    for (unsigned char key = 0; table[key] != NULL; key++) {
        if (peek_lexeme(stream, key) != -1) {
            return key + SEMICOLON;
        }
    }
    return CHARACTER;
}

void
pop_blanks(char **stream)
{
    while (**stream <= ' ') {
        (*stream)++;
    }
}

size_t
pop_characters(char **stream)
{
    size_t popped_length;

    for (popped_length = 0; peek_symbol(*stream) == CHARACTER; popped_length++) {
        (*stream)++;
    }
    return popped_length;
}

// 1. Build lexer/grammar
// 2. Build parser
// 3. Build termios readline
int main(void)
{
    return 0;
}
