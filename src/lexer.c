#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lexer.h"

bool is_token(char *token, TOKEN_KIND *kind)
{
    for (int i = 0; i < TOKEN_SIZE; i++)
    {
        if (strcmp(token, token_string[i]) == 0)
        {
            *kind = i;
            return true;
        }
    }

    return false;
}

bool is_token2(char token, TOKEN_KIND *kind)
{
    for (int i = 0; i < TOKEN_SIZE; i++)
    {
        if (token == token_string[i][0] && token_string[i][1] == 0)
        {
            *kind = i;
            return true;
        }
    }
    return false;
}
bool is_token_type(char token, char test)
{
    for (int i = 0; i < TOKEN_SIZE; i++)
    {
        if (token == test)
        {
            return true;
        }
    }

    return false;
}

bool is_token_separator(char token_char)
{
    if (token_char == ' ' || token_char == '\n' || token_char == ';' || token_char == EOF)
        return true;
    return false;
}

bool is_number(char token)
{
    return token > 47 && token < 58;
}

bool is_alpha(char token)
{
    return (token >= '0' && token <= 9) || (token >= 'A' && token <= 'z');
}

char advance(char **current)
{
    (*current)++;
    return **current;
}

char peek_next(char *current)
{
    return *(current + 1);
}

char *parse_string(char **begin)
{
    char *start = *begin;
    int chars = 1;
    while (peek_next(*begin) != DOUBLE_QUOTE)
    {
        advance(begin);
        chars++;
    }

    char *name = malloc(chars + 1);
    memcpy(name, start, chars);
    name[chars] = 0;

    return name;
}

void parse_tokens(String *program, vector *tokens)
{
    char *begin = program->data;

    (void)tokens;

    Token identifier[128] = {0};
    int num_idents = 0;
    identifier[num_idents].data = malloc(128);
    memset(identifier[num_idents].data, 0, 128);

    TOKEN_KIND token_kind;

    (void)token_kind;

    char current = *begin;

    while (current != 0)
    {

        switch (current)
        {
        case PLUS:
            break;
        case MINUS:
            break;
        case MUL:
            break;
        case DIV:
            break;
        case XOR:
            break;
        case AMP:
            break;
        case PERCENTAGE:
            break;
        case UNDERSCORE:
            break;
        case QUESTION:
            break;
        case BANG:
            break;
        case EQUALS:
            break;
        case OPEN_BRACE:
            break;
        case CLOSE_BRACE:
            break;
        case OPEN_PAR:
            break;
        case CLOSE_PAR:
            break;
        case OPEN_CUR:
            break;
        case CLOSE_CUR:
            break;
        case DOUBLE_QUOTE:
        {
            advance(&begin);
            char *name = parse_string(&begin);
            current = advance(&begin);
            printf("found string: %s\n", name);
            break;
        }
        break;
        case SEMICOLON:
            break;
        case ' ':
        case '\t':
        case '\n':
            break;
        default:
            if (is_number(current))
            {
                break;
            }
            if (is_alpha(current))
            {
                char *start = begin;
                int chars = 0;
                while (is_alpha(current))
                {
                    current = advance(&begin);
                    chars++;
                }

                char *name = malloc(chars + 1);
                memcpy(name, start, chars);
                name[chars] = 0;
                printf("found identifier: %s\n", name);
                break;
            }

            printf("unrecognized symbol: %c", current);
            abort();
            break;
        }

        current = advance(&begin);
    }
    printf("NUM TOKENS: %d\n", num_idents);

    for (int i = 0; i <= num_idents; i++)
    {
        printf("TOKEN: ");
        for (int j = 0; identifier[i].data[j] != 0; j++)
        {
            printf("%c", identifier[i].data[j]);
        }
        printf(" | [%s]", token_string[identifier[i].kind]);
        printf("\n");
    }
}

bool expected_token(Token token, int expected)
{
    (void)token;
    (void)expected;

    (void)token_string;

    return false;
}
