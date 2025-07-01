/*
** EPITECH PROJECT, 2025
** str_cat
** File description:
** str_cat
*/
#include <unistd.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i += 1;
    for (; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return dest;
}
