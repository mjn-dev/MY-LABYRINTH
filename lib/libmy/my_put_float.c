/*
** EPITECH PROJECT, 2025
** handle_float
** File description:
** same use as flag f
*/

#include <stdarg.h>
#include <stdio.h>
#include "includes/my.h"

static void round_nb(int transf, double l)
{
    int integer = l;
    int stock = integer % 10;

    if (stock > 5)
        my_put_nbr(transf % 10 + 1);
    else
        my_put_nbr(transf % 10);
}

void my_put_float(double c, int dec)
{
    int integer = c;
    int transf = 0;
    double l = c - integer;

    my_put_nbr(integer);
    my_putchar('.');
    for (int n = 0; n <= (dec - 2); n++){
        my_printf(" float : %f \n", l);
        l = l * 10;
        transf = l;
        my_put_nbr(transf % 10);
    }
    l = l * 10;
    transf = l;
    round_nb(transf, l);
}
