/*
** EPITECH PROJECT, 2025
** bsmy_radar
** File description:
** my_strchr
*/

#include "includes/my.h"

char *my_strchr(const char *string, int c)
{
    char ch = (char)c;

    while (*string != '\0') {
        if (*string == ch) {
            return (char *)string;
        }
        string++;
    }
    if (ch == '\0') {
        return (char *)string;
    }
    return NULL;
}
