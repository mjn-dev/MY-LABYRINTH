/*
** EPITECH PROJECT, 2025
** task 2 - day 4
** File description:
** task 2 - day 4
*/
#include <unistd.h>
#include "includes/my.h"

int my_putstr(char const *str, int *count)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i], count);
        i = i + 1;
    }
    return 0;
}
