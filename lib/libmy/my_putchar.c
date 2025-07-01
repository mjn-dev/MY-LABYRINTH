/*
** EPITECH PROJECT, 2025
** my_putchar
** File description:
** my_putchar
*/
#include <unistd.h>

void my_putchar(char c, int *count)
{
    write(1, &c, 1);
    *count += 1;
}
