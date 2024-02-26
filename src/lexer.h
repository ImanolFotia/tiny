#ifndef LEXER_INCLUDED
#define LEXER_INCLUDED

#include <stdbool.h>
#include "utils/string_builder.h"
#include "utils/vector.h"

typedef enum
{
    IF = 0,
    WHILE,
    FOR,
    INT,
    FLOAT,
    CHAR,
    STRING,
    BOOL,
    TOKEN_SIZE,
    STRING_LITERAL,
    NUMBER_LITERAL,
    IDENTIFIER,
    UNKNOWN
} TOKEN_KIND;

static const char *token_string[] = {"string literal", "number literal", "identifier", "unknown"};

static const char *reserved_words[] = {"if", "while", "do", "for", "int", "float", "char", "string", "bool", "switch", "case"};

#define PLUS '+'
#define MINUS '-'
#define MUL '*'
#define DIV '/'
#define XOR '^'
#define AMP '&'
#define PERCENTAGE '%'
#define UNDERSCORE '_'
#define QUESTION '?'
#define BANG '!'
#define EQUALS '='
#define OPEN_BRACE '['
#define CLOSE_BRACE ']'
#define OPEN_PAR '('
#define CLOSE_PAR ')'
#define OPEN_CUR '{'
#define CLOSE_CUR '}'
#define DOUBLE_QUOTE '"'
#define SEMICOLON ';'

typedef struct Token_t
{
    TOKEN_KIND kind;
    char *data;
} Token;

bool expected_token(Token token, int expected);
void parse_tokens(String *program, vector *tokens);
bool is_token(char *token, TOKEN_KIND *kind);
bool is_number(char token);
bool is_alpha(char token);

#endif // LEXER_INCLUDED
