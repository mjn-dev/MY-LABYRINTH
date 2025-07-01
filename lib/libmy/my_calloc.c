/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** my_calloc
*/
#include <stdlib.h>
#include "includes/my.h"

void *my_calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(nmemb * size);

    if (ptr == NULL)
        return NULL;
    my_memset(ptr, 0, nmemb * size);
    return ptr;
}
