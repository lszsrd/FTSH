#ifndef LEXER_H
#define LEXER_H

#define LOCKED                  0
#define UNLOCKED                1

#define UNKNOWN                 (unsigned) 0xFFFFFFF

#define MAX_HEAP_ALPHABET       32
#define MAX_HEAP_LEXEM          1024

enum token {
    CHARACTER                   = 0,
    WORD                        = 1,
    NUMBER                      = 2,
    ARITHMETIC_OPERATOR         = 3,
    REDIRECTION                 = 4,
    OPERATOR                    = 5,
    JOB_CONTROL                 = 6,
    COMPOUND                    = 7,
};

enum symbol {
    INTEGER                     = 0,
    UPPER_CASE                  = 1,
    LOWER_CASE                  = 2,
    BLANK                       = 4,
    ARITHMETIC                  = 8,
    PLUS                        = 16,
    DASH                        = 32,
    SLASH                       = 64,
    PONCTUATION                 = 128,
    NEWLINE                     = 256,
    BINARY                      = 512,
    JOB                         = 1024,
    IO                          = 2048,
};

struct dict {
    enum symbol symbol;
    const char *alphabet[MAX_HEAP_ALPHABET];
};

const struct dict dictionary[] = {
    { INTEGER                   , { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" } },
    { UPPER_CASE                , { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" } },
    { LOWER_CASE                , { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" } },
    { BLANK                     , { " ", "\t" } },
    { ARITHMETIC                , { "%", "*" } },
    { PLUS                      , { "+" }},
    { DASH                      , { "-" } },
    { SLASH                     , { "/" } },
    { PONCTUATION               , { "#", "$", ",", ".", ":", ";", "?", "@", "_" } },
    { NEWLINE                   , { "\n" } },
    { BINARY                    , { "&&", "||", "|" } },
    { JOB                       , { "&" } },
    { IO                        , { ">>", ">", "<<", "<" } },
    { UNKNOWN                   , { 0 } }
};

struct grammar {
    enum token token;
    __typeof__(UNKNOWN) grammar;
};

const struct grammar grammar[] = {
    { CHARACTER                 , INTEGER
                                | UPPER_CASE
                                | LOWER_CASE
                                | BLANK
                                | DASH
                                | SLASH },
    { WORD                      , CHARACTER
                                | WORD },
    { NUMBER                    , INTEGER
                                | (NUMBER & INTEGER)
                                | (DASH & INTEGER) },
    { ARITHMETIC_OPERATOR       , ARITHMETIC
                                | DASH
                                | SLASH },
    { REDIRECTION               , WORD & IO & WORD },
    { OPERATOR                  , (BINARY & (WORD | REDIRECTION))
                                | ((WORD | REDIRECTION) & BINARY & (WORD | REDIRECTION)) },
    { JOB_CONTROL               , (WORD | REDIRECTION) & JOB },
    { COMPOUND                  , WORD
                                | (WORD & NEWLINE)
                                | REDIRECTION
                                | (REDIRECTION & NEWLINE)
                                | OPERATOR
                                | (OPERATOR & NEWLINE)
                                | COMPOUND },
    { UNKNOWN                   , 0 },
};

struct lexeme {
    enum token token;
    unsigned char ready:1;
    char attribute[MAX_HEAP_LEXEM];
};

static struct lexeme lexeme = { UNKNOWN, UNLOCKED, {0} };

#endif /* ! LEXER_H */
