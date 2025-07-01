/*
** EPITECH PROJECT, 2025
** libs
** File description:
** my_memcpy
*/

#include "./includes/my.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;

    if (dest == NULL || src == NULL)
        return NULL;
    while (n > 0) {
        *d = *s;
        d++;
        s++;
        n--;
    }
    return dest;
}
