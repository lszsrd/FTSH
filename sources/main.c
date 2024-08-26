#include <string.h>
#include <stdio.h>

#include "lexer.h"

static struct lexeme lexeme = {0};

static enum symbol peek_symbol(const char *stream)
{
    for (enum symbol key = 0; dictionary[key].symbol != UNKNOWN; key++) {
        for (unsigned char value = 0; dictionary[key].alphabet[value] != NULL; value++) {
            if (strncmp(dictionary[key].alphabet[value], stream, strlen(dictionary[key].alphabet[value])) == 0) {
                return dictionary[key].symbol;
            }
        }
    }
    return UNKNOWN;
}

void pop_token(char **stream)
{
    *stream += strlen(lexeme.attribute);
}

unsigned char peek_token(const char *stream)
{
    memset(lexeme.attribute, 0, MAX_HEAP_LEXEM);
    return 0;
}

int main(void)
{
    return 0;
}
