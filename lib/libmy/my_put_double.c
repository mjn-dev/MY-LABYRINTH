/*
** EPITECH PROJECT, 2025
** dispaly double
** File description:
** display double
*/

#include "includes/my.h"
#include <stdio.h>

void my_put_double(double nb, int *count)
{
    int integer = 0;
    int dec = 0;
    double stocki = 0;

    if (nb < 0){
        nb = nb * -1;
        my_putchar('-', count);
    }
    integer = nb;
    my_put_nbr(integer, count);
    my_putchar('.', count);
    stocki = (nb - integer);
    if (stocki == 0)
        my_putstr("000000", count);
    stocki = stocki + 0.0000005;
    stocki = stocki * 1000000;
    dec = stocki;
    my_put_nbr(dec, count);
}

/*int main(void)
{
    my_put_double(1.4444446);
    return 0;
}
*/
