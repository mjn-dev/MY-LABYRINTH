/*
** EPITECH PROJECT, 2025
** handle_n.c
** File description:
** handle_n.c
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include "includes/my.h"

void handle_n(va_list args, int *count)
{
    int *nb = va_arg(args, int *);

    my_swap(nb, count);
    *count = *nb;
}
