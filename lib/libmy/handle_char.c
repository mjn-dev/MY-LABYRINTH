/*
** EPITECH PROJECT, 2025
** handle char
** File description:
** print char
*/

#include "includes/my.h"
#include <stdarg.h>

void handle_char(va_list args, int *count)
{
    char param = va_arg(args, int);

    my_putchar(param, count);
}
