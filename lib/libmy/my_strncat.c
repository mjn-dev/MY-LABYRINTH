/*
** EPITECH PROJECT, 2025
** my_strncat.c
** File description:
** my_strncat.c
*/

#include <unistd.h>
#include <stdio.h>

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i += 1;
    for (; src[j] != '\0' && j < n; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return dest;
}
