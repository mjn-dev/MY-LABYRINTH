/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myradar-philibert.gentien
** File description:
** my_putnbr_base
*/

#include "includes/my.h"

int is_char_in_base(char c, char const *base)
{
    for (int i = 0; base[i] != '\0'; i++) {
        if (base[i] == c)
            return 1;
    }
    return 0;
}

int is_base_valid(char const *base)
{
    int base_len = my_strlen(base);

    if (base_len <= 1 || !base || base_len > 100)
        return 0;
    for (int j = 0; base[j] != '\0'; j++) {
        if (is_char_in_base(base[j], base + j + 1))
            return 0;
    }
    return 1;
}

int handle_negative(int *nbr)
{
    if (*nbr < 0) {
        *nbr = -(*nbr);
        return 1;
    }
    return 0;
}

int my_putnbr_base(int nbr, char const *base)
{
    int count = 0;
    int is_negative = 0;

    if (!is_base_valid(base))
        return -1;
    is_negative = handle_negative(&nbr);
    if (is_negative)
        my_putchar('-', &count);
    my_convert_base((unsigned long)nbr, (char *)base, &count);
    return count;
}
