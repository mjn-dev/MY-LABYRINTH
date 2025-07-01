/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** my_putstr_err
*/

#include "my.h"

int my_putstr_err(char const *str, int rtv)
{
    write(STDERR_FILENO, str, my_strlen(str));
    return rtv;
}
