#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

static unsigned short lookup_table_scanner(char *stream, enum lexeme key)
{
    for (unsigned char value = 0; table[key].data[value] != NULL; value++) {
        if ( strncmp(lookup_table[key][value], stream, strlen(lookup_table[key][value])) == 0 ) {
            return value;
        }
    }
    return UNKNOWN;
}

static enum lexeme lexeme_scanner(char *stream)
{
    if ( *stream == '\0' ) {
        return UNKNOWN;
    }

    for (enum lexeme key = 0; table[key].key != UNKNOWN; key++) {
        if ( lookup_table_scanner(stream, key) != UNKNOWN ) {
            return table[key].key;
        }
    }
    return STRING;
}

static char *string_scanner(char **stream)
{
    size_t litteral_length;

    for (litteral_length = 0; lexeme_scanner(*stream) == STRING; (*stream)++) {
        litteral_length++;
    }
    return strndup(*stream - litteral_length, litteral_length);
}

static struct token *scanner(char **stream)
{
    static enum lexeme lexeme;
    struct token *token;

    for (; **stream == ' ' || **stream == '\t'; (*stream)++);

    if ( (lexeme = lexeme_scanner(*stream)) == UNKNOWN || (token = calloc(1, sizeof(*token))) == NULL ) {
        return NULL;
    }

    if ( (token->lexeme = lexeme) == STRING ) {
        token->data = string_scanner(stream);
    } else {
        token->data = (void *) (long) lookup_table_scanner(*stream, lexeme);
        *stream += strlen(table[lexeme].data[(size_t) token->data]);
    }
    return token;
}

struct token **lexer(char **stream)
{
    struct token **tokens = calloc(32, sizeof(tokens));

    if ( tokens == NULL ) {
        return NULL;
    }

    for (size_t index = 0; ( tokens[index] = scanner(stream) ) != NULL; index++);
    return tokens;
}

int main(void)
{
    //__builtin_ctz(2);
    /*
    struct token ** t;
    char *b = NULL;
    size_t l = 0;

    while (getline(&b, &l, stdin) != EOF) {
        t = lexer(&b);
        for (int i = 0; t && t[i]; i++) {
            printf("[%d] ", t[i]->lexeme);
            if (t[i]->lexeme == STRING) free(t[i]->data);
            free(t[i]);
        }
        free(t);
        printf("\n");
    }
    free(b);
    */
    printf("%d\n", lexeme_scanner("&&"));
    return 0;
}
