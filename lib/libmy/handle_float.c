/*
** EPITECH PROJECT, 2025
** handle_float
** File description:
** same use as flag f
*/

#include <stdarg.h>
#include "includes/my.h"

void handle_float(va_list args, int *count)
{
    float param = va_arg(args, double);

    my_put_double(param, count);
}
