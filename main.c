#include "utils/string_builder.h"
#include "lexer.h"
#include "utils/vector.h"

int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        printf("error: no input files\n");
        fflush(stdout);
        exit(255);
    }
    String file_content;
    bool result = read_entire_file(argv[1], &file_content);

    (void)(argc);
    (void)(argv);

    (void)token_string;

    if (!result)
    {
        printf("File open failed\n");
    }

    vector tokens;
    vector_init(&tokens, 50, sizeof(Token));

    printf("%s\n", file_content.data);

    parse_tokens(&file_content, &tokens);

    vector_free(&tokens);

    free(file_content.data);

    return 0;
}
