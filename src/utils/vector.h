// Yes, I'm a C++ dev how could you tell???
#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INT2VOIDP(i) (void *)(uintptr_t)(i)
#define CAST_AS(t, i) (*(t *)(i))
typedef struct vector_t
{
    unsigned char *data;
    size_t size;
    size_t capacity;
    size_t item_size;

    unsigned char *(*at)(struct vector_t *, size_t);
    void (*push_back)(struct vector_t *, void *);
    void (*resize)(struct vector_t *, size_t);
} vector;

unsigned char *vector_at(vector *array, size_t position);
void vector_push_back(vector *array, void *data);
void vector_resize(vector *array, size_t new_size);
void vector_init(vector *array, size_t num_items, size_t type_size);
void vector_free(vector *array);

#endif //_vector_H_
