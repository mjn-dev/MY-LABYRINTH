/*
** EPITECH PROJECT, 2025
** my_strncpy.
** File description:
** copy n charachters of src string into dest string
*/
#include <stdio.h>
#include <string.h>

static int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int src_len = my_strlen(src);

    for (; i < n; i++) {
        if (n > src_len)
            dest[i] = '\0';
        dest[i] = src[i];
    }
    return dest;
}
