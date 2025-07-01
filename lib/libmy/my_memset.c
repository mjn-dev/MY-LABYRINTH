/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** my_memset
*/

#include <stddef.h>

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *ptr = (unsigned char *)s;
    size_t i = 0;

    while (i < n) {
        ptr[i] = (unsigned char)c;
        i++;
    }
    return s;
}
