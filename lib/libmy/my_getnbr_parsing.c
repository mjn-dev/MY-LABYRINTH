/*
** EPITECH PROJECT, 2025
** my_getnbr_parsing
** File description:
** get_nbr
*/

#include <stdio.h>

static int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

static int check_minus(char const str, int factor)
{
    if (str == '-') {
        factor = factor * -1;
        return factor;
    }
    return 0;
}

static int handle_null_input(int *error)
{
    if (error != NULL)
        *error = 84;
    return 0;
}

static int handle_overflow(long long result, int factor, int *error)
{
    if ((result * factor) > 2147483647 || (result * factor) < -2147483648) {
        if (error != NULL)
            *error = 84;
        return 1;
    }
    return 0;
}

int my_getnbr_parsing(char const *str, int *error)
{
    int i = 0;
    long long result = 0;
    int factor = 1;

    if (error != NULL)
        *error = 0;
    if (str == NULL)
        return handle_null_input(error);
    for (; str[i] != '\0' && is_digit(str[i]) == 0; i++)
        factor = (str[i] == '+') ? factor : check_minus(str[i], factor);
    for (; str[i] != '\0' && is_digit(str[i]) == 1; i++)
        result = (result * 10) + (str[i] - '0');
    if (str[i] != '\0' && str[i] != ' ') {
        if (error != NULL)
            *error = 84;
        return 0;
    }
    if (handle_overflow(result, factor, error))
        return 0;
    return (int)(result * factor);
}
