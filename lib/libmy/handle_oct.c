/*
** EPITECH PROJECT, 2025
** my_put_octal
** File description:
** my_put_octal
*/

#include <stdarg.h>
#include "includes/my.h"

void handle_oct(va_list args, int *count)
{
    char base[] = "01234567";
    unsigned int result = va_arg(args, int);

    my_convert_base(result, base, count);
}
