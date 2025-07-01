/*
** EPITECH PROJECT, 2025
** my_put_octal
** File description:
** my_put_octal
*/

#include <unistd.h>
#include <stdio.h>
#include "includes/my.h"

void my_convert_base(unsigned long nb, char *base, int *count)
{
    int base_len = my_strlen(base);

    if (nb / base_len != 0)
        my_convert_base((nb / base_len), base, count);
    my_putchar(base[nb % base_len], count);
}
/*
int main(void)
{
    my_convert_base(10, "0123456789ABCDEF");
    my_convert_base(10, "0123456789abcdef");
    my_convert_base(10, "01");
    return 0;
    }*/
