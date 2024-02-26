#include "string_builder.h"

bool read_entire_file(const char *path, String *output)
{

    FILE *input_file = fopen(path, "r");

    if (input_file == NULL)
    {
        printf("Couldn't open file: %s\n", path);
        abort();
    }

    size_t count = 0;
    while (fgetc(input_file) != EOF)
    {
        count++;
    }

    if (count == 0)
    {

        printf("File is empty");
        return false;
    }
    rewind(input_file);

    output->data = malloc(count);
    count = 0;
    char c = fgetc(input_file);

    while (c != EOF)
    {
        output->data[count] = c;
        c = fgetc(input_file);
        count++;
    }

    fclose(input_file);
    return true;
}
