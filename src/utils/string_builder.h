#ifndef STRING_BUILDER_INCLUDED
#define STRING_BUILDER_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char *data;
    size_t size;
} String;

bool read_entire_file(const char *path, String *output);

#endif
