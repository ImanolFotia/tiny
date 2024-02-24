#ifndef LEXER_INCLUDED
#define LEXER_INCLUDED

#include <stdbool.h>

enum TOKEN_KIND
{
    IF,
    WHILE,
    FOR,
    PLUS,
    MINUS,
    MUL,
    DIV,
    OPEN_BRACE,
    CLOSE_BRACE,
    OPEN_PAR,
    CLOSE_PAR,
    OPEN_CUR,
    CLOSE_CUR,
    NUMBER,
    LITERAL,
    TYPE,
};

enum TYPES
{
    INT,
    FLOAT,
    CHAR,
    STRING,
    BOOL
};

static const char *token_string[] = {"if", "while", "for", "+", "-", "*", "/", "[", "]", "{", "}", "(", ")"};

static const char *type_string[] = {"int", "float", "char", "string", "bool"};

typedef struct Token_t
{
    enum TOKEN_KIND kind;
} Token;

bool expected_token(Token token, int expected);

#endif // LEXER_INCLUDED
