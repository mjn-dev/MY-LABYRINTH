/*
** EPITECH PROJECT, 2025
** libs
** File description:
** my_realloc
*/

#include "./includes/my.h"

void *my_realloc(void *ptr, size_t size_alloc, size_t size)
{
    void *new_ptr;

    if (ptr == NULL)
        return malloc(size);
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    new_ptr = malloc(size);
    if (new_ptr == NULL)
        return NULL;
    my_memcpy(new_ptr, ptr, size_alloc < size ? size_alloc : size);
    free(ptr);
    return new_ptr;
}
