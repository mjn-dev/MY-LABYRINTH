/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** my_getnbr
*/

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

int my_getnbr(char const *str)
{
    int i = 0;
    long long result = 0;
    int factor = 1;

    for (; str[i] != '\0' && is_digit(str[i]) == 0; i++) {
        if (str[i] == '+') {
            continue;
        } else {
            factor = check_minus(str[i], factor);
        }
    }
    for (; str[i] != '\0' && is_digit(str[i]) == 1; i++) {
        result = (result * 10) + (str[i] - '0');
    }
    if ((result * factor) > 2147483647 || (result * factor) < -2147483648)
        return 0;
    return (int)result * factor;
}
