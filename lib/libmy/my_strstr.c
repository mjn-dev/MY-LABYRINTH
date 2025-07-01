/*
** EPITECH PROJECT, 2025
** my_strstr.c
** File description:
** my_strstr.c
*/
#include <stddef.h>

static int is_find(char *str, char const *to_find, int i, int j)
{
    for (; str[i] == to_find[j] || to_find[j] == '\0'; j++) {
        if (to_find[j] == '\0')
            return 1;
        i++;
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int result = 0;

    if (to_find[0] == '\0')
        return str;
    for (; str[i] != '\0'; i++) {
        if (str[i] == to_find[0]) {
            k = i;
            result = is_find(str, to_find, i, j);
        }
        if (result == 1)
            return &str[k];
    }
    return NULL;
}
