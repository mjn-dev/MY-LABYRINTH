/*
** EPITECH PROJECT, 2025
** handle str
** File description:
** print str
*/

#include "includes/my.h"
#include <stdarg.h>

void handle_str(va_list args, int *count)
{
    char *param = va_arg(args, char *);

    my_putstr(param, count);
}
