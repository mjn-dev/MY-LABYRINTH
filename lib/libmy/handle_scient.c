/*
** EPITECH PROJECT, 2025
** handle scient
** File description:
** display scient write
*/

#include "includes/my.h"
#include <stdarg.h>

void handle_scient(va_list args, int *count)
{
    double param = va_arg(args, double);

    my_put_scient(param, count);
}
