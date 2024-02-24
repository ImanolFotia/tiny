#include "utils/string_builder.h"
#include "lexer.h"

static Token *tokens;

int main(int argc, char *argv[])
{
    struct String file_content;
    bool result = read_entire_file("tiny.txt", &file_content);

    (void)(tokens);
    (void)(argc);
    (void)(argv);

    (void)token_string;
    (void)type_string;

    if (!result)
    {
        printf("File open failed\n");
    }

    printf("%s\n", file_content.data);

    free(file_content.data);

    return 0;
}
