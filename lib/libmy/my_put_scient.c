/*
** EPITECH PROJECT, 2025
** display scient
** File description:
** display scient
*/

#include "includes/my.h"
#include <stdio.h>

static double e_scient(double nb, int *count)
{
    int i = 0;

    if (nb < 0) {
        my_putchar('-', count);
        nb = nb * -1;
    }
    for (; nb > 10; i++) {
        nb = nb / 10;
    }
    for (; nb < 1; i++) {
        nb = nb * 10;
    }
    my_put_double(nb, count);
    return i;
}

static void plus_or_less(double nb, int *count)
{
    if (nb < 0)
        nb = nb * -1;
    if (nb < 1)
        my_putchar('-', count);
    else
        my_putchar('+', count);
}

void my_put_scient(double nb, int *count)
{
    int i = e_scient(nb, count);

    my_putchar('e', count);
    plus_or_less(nb, count);
    if (i < 10) {
        my_putchar('0', count);
        my_put_nbr(i, count);
    } else {
        my_put_nbr(i, count);
    }
}

/*int main(void)
{
    double v = 0.0004988;

    my_put_scient(v);
}
*/
