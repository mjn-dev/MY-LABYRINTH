/*
** EPITECH PROJECT, 2025
** handle_hex.c
** File description:
** handle_hex.c
*/

#include <stdarg.h>
#include "includes/my.h"

void handle_hex(va_list args, int *count)
{
    char base[] = "0123456789ABCDEF";
    unsigned int result = va_arg(args, int);

    my_convert_base(result, base, count);
}
