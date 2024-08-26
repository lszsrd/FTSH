#include <string.h>
#include <stdio.h>

#include "lexer.h"

static __typeof__(UNKNOWN) peek_attribute(const char *stream, enum symbol key)
{
    for (unsigned char value = 0; dictionary[key].alphabet[value] != NULL; value++) {
        if (strncmp(dictionary[key].alphabet[value], stream, strlen(dictionary[key].alphabet[value])) == 0) {
            return value;
        }
    }
    return UNKNOWN;
}

static __typeof__(UNKNOWN) peek_symbol(const char *stream)
{
    for (unsigned char key = 0; dictionary[key].symbol != UNKNOWN; key++) {
        if (peek_attribute(stream, key) != UNKNOWN) {
            return key;
        }
    }
    return UNKNOWN;
}

void pop_token(char **stream)
{
    *stream += strlen(lexeme.attribute);
}

void peek_token(const char *stream)
{
    enum symbol keys[2] = { peek_symbol(stream), UNKNOWN };
    enum token token = UNKNOWN;

    if (lexeme.ready == LOCKED) {
        return;
    }

    if (*keys != UNKNOWN) {
        __typeof__(UNKNOWN) value = peek_attribute(stream, *keys);
        keys[1] = peek_symbol(stream + strlen(dictionary[*keys].alphabet[value]));

        // TODO: Not looking at the correct token, preventing grammar to stop
        for (token = 0; grammar[token].token != UNKNOWN; token++) {
            if ((grammar[token].grammar | (keys[0] & keys[1])) == grammar[token].grammar) {
                break;
            }
        }

        strcat(lexeme.attribute, dictionary[*keys].alphabet[value]);
        peek_token(stream + 1);
    }

    lexeme.ready = LOCKED;
    lexeme.token = token;
}

void clear_token(void)
{
    lexeme.ready = UNLOCKED;
    lexeme.token = UNKNOWN;
    memset(lexeme.attribute, 0, MAX_HEAP_LEXEM);
}
\
int main(void)
{
    peek_token("ls > a ; bè");
    printf("%d - %s\n", lexeme.token, lexeme.attribute);
    return 0;
}
