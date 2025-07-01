/*
** EPITECH PROJECT, 2025
** handle_u.c
** File description:
** handle_u.c
*/

#include "includes/my.h"
#include <stdarg.h>

static void print_u(long long int nb, int *count)
{
    unsigned int val_max = 4294967295;

    if (nb < 0) {
        nb = val_max + nb;
        my_put_long((long long)nb, count);
    } else {
        my_put_long((long long)nb, count);
    }
}

void handle_u(va_list args, int *count)
{
    long long int nb = va_arg(args, long long);

    print_u(nb, count);
}
