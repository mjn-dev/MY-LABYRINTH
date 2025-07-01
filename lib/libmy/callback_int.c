/*
** EPITECH PROJECT, 2025
** my
** File description:
** callback_int
*/

#include "includes/my.h"

void print_int(void *data)
{
    my_printf("%d -> ", *(int *)data);
}

int compare_int(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

void free_int(void *data)
{
    free(data);
}
