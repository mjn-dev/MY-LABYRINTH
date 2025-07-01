/*
** EPITECH PROJECT, 2025
** strdup.c
** File description:
** strdup.c
*/
#include <stdlib.h>
#include <stdio.h>
#include "includes/my.h"

char *my_strdup(char const *src)
{
    int src_len = my_strlen(src);
    char *dest;

    dest = malloc(sizeof(char) * (src_len + 1));
    my_strcpy(dest, src);
    return dest;
}
