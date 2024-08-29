#ifndef LEXER_H
#define LEXER_H

// ls -a > logfile.txt && cd - ;
// [STRING] [REDIRECTION] [STRING] [OPERATOR] [STRING] [SEMICOLON] [NEWLINE]
//
// ls &
// [STRING] [JOBCONTROL] [NEWLINE]
//
// ls && ((cd -) || echo OK) ;
// [STRING] [OPERATOR] [OPEN] [OPEN] [STRING] [CLOSE] [OPERATOR] [STRING] [CLOSE] [SEMICOLON] [NEWLINE]
//
// 1. Tokenize string - DONE
// 2. Store produced tokens into a list (pushing tokens)
// 3. Parse tokens with a grammar
// And voila

#define BIT(x) 1 << x

struct dict {
    int key;
    const char **data;
};

const char **lookup_table[] = {
    (const char *[]) { "\n", (void *) 0 },
    (const char *[]) { ";", (void *) 0 },
    (const char *[]) { "(", ")", (void *) 0 },
    (const char *[]) { ">>", ">", "<<", "<", (void *) 0 },
    (const char *[]) { "&&", "||", "|", (void *) 0 },
    (const char *[]) { "\"", "'", (void *) 0 },
    (const char *[]) { "&", (void *) 0 },
    (void *) 0,
};

enum lexeme {
    NEWLINE = BIT(0),
    SEMICOLON = BIT(1),
    PARENTHESIS = BIT(2),
    REDIRECTION = BIT(3),
    PIPELINE = BIT(4),
    QUOTE = BIT(5),
    BACKGROUND = BIT(6),
    STRING = BIT(7),
    UNKNOWN = 0xFFFF,
};

// 8 4 2 1
//

struct dict table[] = {
    { NEWLINE, (const char *[]) { "\n", (void *) 0 } },
    { SEMICOLON, (const char *[]) { ";", (void *) 0 } },
    { PARENTHESIS, (const char *[]) { "(", ")", (void *) 0 } },
    { REDIRECTION, (const char *[]) { ">>", ">", "<<", "<", (void *) 0 } },
    { PIPELINE, (const char *[]) { "&&", "||", "|", (void *) 0 } },
    { QUOTE, (const char *[]) { "\"", "'", (void *) 0 } },
    { BACKGROUND, (const char *[]) { "&", (void *) 0 } },
    { UNKNOWN, (void *) 0 },
};

struct token {
    enum lexeme lexeme;
    void *data;
};

#endif /* ! LEXER_H */
