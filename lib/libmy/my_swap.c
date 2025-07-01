/*
** EPITECH PROJECT, 2025
** task1 - day 4
** File description:
** task 1 - day 4
*/
#include <unistd.h>

void my_swap(int *a, int *b)
{
    int intermediar;

    intermediar = *a;
    *a = *b;
    *b = intermediar;
    return;
}
