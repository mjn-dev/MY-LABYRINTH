/*
** EPITECH PROJECT, 2025
** bsmy_radar
** File description:
** my_strtok
*/

#include "includes/my.h"

char *my_strtok(char *str, const char *delim)
{
    static char *last = NULL;
    char *token;

    if (str == NULL)
        str = last;
    if (str == NULL)
        return NULL;
    while (*str && my_strchr(delim, *str))
        str++;
    if (*str == '\0')
        return NULL;
    token = str;
    while (*str && !my_strchr(delim, *str))
        str++;
    if (*str) {
        *str = '\0';
        last = str + 1;
    } else
        last = NULL;
    return token;
}
