#ifndef LEXER_H
#define LEXER_H

enum symbol {
    TOKEN_COMPOUND              = 1,
    TOKEN_COMMAND               = 2,
    TOKEN_SHELL                 = 4,
    TOKEN_OPERATOR              = 8,
    TOKEN_IO                    = 16,
    TOKEN_LITTERAL              = 32,

    SEMICOLON                   = TOKEN_LITTERAL + 1,
    OPEN_PARENTHESIS            ,
    CLOSE_PARENTHESIS           ,
    SEPARATOR                   ,
    REDIRECTION                 ,
    CHARACTER                   ,
};

struct grammar {
    enum symbol token;
    unsigned char entries;
    enum symbol *symbols;
};

const char **table[] = {
    (const char *[]) { ";", 0 },
    (const char *[]) { "(", 0 },
    (const char *[]) { ")", 0 },
    (const char *[]) { "&&", 0 },
    (const char *[]) { "||", 0 },
    (const char *[]) { "|", 0 },
    (const char *[]) { ">>", ">", "<<", "<", 0 },
    0,
};

const struct grammar grammar[] = {
    { TOKEN_COMPOUND,           1, (enum symbol []) { TOKEN_COMMAND | TOKEN_SHELL | TOKEN_OPERATOR | TOKEN_IO | TOKEN_LITTERAL } },

    { TOKEN_COMMAND,            3, (enum symbol []) { TOKEN_COMPOUND, SEMICOLON, TOKEN_COMPOUND } },
    { TOKEN_COMMAND,            2, (enum symbol []) { TOKEN_COMPOUND, SEMICOLON } },
    { TOKEN_COMMAND,            2, (enum symbol []) { SEMICOLON, TOKEN_COMPOUND } },
    { TOKEN_COMMAND,            1, (enum symbol []) { SEMICOLON } },

    { TOKEN_SHELL,              3, (enum symbol []) { OPEN_PARENTHESIS, TOKEN_COMPOUND, CLOSE_PARENTHESIS } },
    { TOKEN_OPERATOR,           3, (enum symbol []) { TOKEN_COMPOUND, SEPARATOR, TOKEN_COMPOUND } },
    { TOKEN_IO,                 3, (enum symbol []) { TOKEN_COMPOUND, REDIRECTION, TOKEN_COMPOUND } },
    { TOKEN_LITTERAL,           1, (enum symbol []) { CHARACTER | TOKEN_LITTERAL } },
};

// ls > f '\0'
// ^  ^ ^  ^
// |  | |  |
// +-------------|> try compound
//    | |  |     |> try command
//    | |  |     |> try shell
//    | |  |     |> try operator
//    | |  |     |> try io
//    | |  |     |> try litteral : MATCH
//    | |  |
//    +----------|> try compound   @ index[1]
//      |  |     |> try command    @ index[1]
//      |  |     |> try shell      @ index[1]
//      |  |     |> try operator   @ index[1]                                               MATCH
//      |  |     |> try io         @ index[1] : MATCH : seek for io @ index[2] -> compound <|---+  //---+
//      |  |                                            \   recursive call   /                  |       |
//      +--------|> try compound                                                                |       |
//         |     |> try command                                                                 |       |
//         |     |> try shell                                                                   |       |
//         |     |> try operator                                                                |       |
//         |     |> try io                                                                      |       |
//         |     |> try litteral : MATCH  ------------------------------------------------------+       |
//         |                                                                                            |
//         +-----|> END OF STREAM : return TOKEN_IO  <|-------------------------------------------------+

struct token {
    enum symbol token:16;
    unsigned short column;
    unsigned short length;
    unsigned char grammar;
    struct token *next;
};

#endif /* !LEXER_H */
