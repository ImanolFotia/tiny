#ifndef STRING_BUILDER_INCLUDED
#define STRING_BUILDER_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct String
{
    char *data;
    size_t size;
};

bool read_entire_file(const char *path, struct String *output);

#endif
