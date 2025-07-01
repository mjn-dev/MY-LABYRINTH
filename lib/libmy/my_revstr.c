/*
** EPITECH PROJECT, 2025
** my_revstr.c
** File description:
** reverse a string
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

static void my_swap_char(char *a, char *b)
{
    char intermediar;

    intermediar = *a;
    *a = *b;
    *b = intermediar;
    return;
}

char *my_revstr(char *str)
{
    int a = my_strlen(str) -1;

    if (str == NULL)
        return NULL;
    for (int i = 0; i < a; i++) {
        my_swap_char(&str[i], &str[a]);
        a = a - 1;
    }
    return str;
}
