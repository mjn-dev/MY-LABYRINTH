/*
** EPITECH PROJECT, 2025
** handle int
** File description:
** print int
*/

#include "includes/my.h"
#include <stdarg.h>

void handle_int(va_list args, int *count)
{
    int param = va_arg(args, int);

    my_put_nbr(param, count);
}
