#include "vector.h"

void vector_init(vector *array, size_t num_items, size_t type_size)
{
    array->data = (unsigned char *)calloc(num_items, type_size);
    memset((unsigned char *)array->data, 0, num_items * type_size);
    array->capacity = num_items;
    array->size = 0;
    array->item_size = type_size;

    array->at = &vector_at;
    array->push_back = &vector_push_back;
    array->resize = &vector_resize;
}

unsigned char *vector_at(vector *array, size_t position)
{
    if (position >= array->size)
    {
        printf("fatal: out of bound array access");
        abort();
    }
    return &array->data[position * array->item_size];
}

void vector_resize(vector *array, size_t new_size)
{
    array->data = (unsigned char *)realloc(array->data, new_size);
}

void vector_push_back(vector *array, void *data)
{
    if (array->size >= array->capacity)
    {
        vector_resize(array, array->capacity * 2);
        array->capacity *= 2;
    }
    for (size_t i = 0; i < array->item_size; i++)
    {
        array->data[array->size * array->item_size + i] = ((unsigned char *)&data)[i];
    }
    array->size++;
}

void vector_free(vector *array)
{
    free(array->data);
}
