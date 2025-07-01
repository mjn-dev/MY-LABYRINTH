/*
** EPITECH PROJECT, 2025
** task7
** File description:
** task7
*/
#include <unistd.h>
#include "includes/my.h"

void my_put_nbr(int n, int *count)
{
    if (n == -2147483648) {
        my_putchar('-', count);
        my_putchar('2', count);
        my_put_nbr(147483648, count);
        return;
    }
    if (n < 0) {
        my_putchar('-', count);
        n = -n;
    }
    if (n / 10 != 0) {
        my_put_nbr((n / 10), count);
    }
    my_putchar((n % 10 + '0'), count);
}
