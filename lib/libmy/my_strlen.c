/*
** EPITECH PROJECT, 2025
** task 3 - day 4
** File description:
** task 3 - day 4
*/

#include <unistd.h>
#include "includes/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}
