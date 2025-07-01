/*
** EPITECH PROJECT, 2025
** handle_p.c
** File description:
** handle_p.c
*/
#include <stdarg.h>
#include "includes/my.h"

void handle_p(va_list args, int *count)
{
    int *ptr = va_arg(args, int *);

    my_putstr("0x", count);
    my_convert_base((unsigned long)ptr, "0123456789abcdef", count);
}
