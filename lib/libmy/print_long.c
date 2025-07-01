/*
** EPITECH PROJECT, 2025
** print long
** File description:
** print long
*/
#include "includes/my.h"

void my_put_long(long long n, int *count)
{
    if (n < 0) {
        my_putchar('-', count);
        n = -n;
    }
    if (n / 10 != 0) {
        my_put_nbr((n / 10), count);
    }
    my_putchar((n % 10 + '0'), count);
}
