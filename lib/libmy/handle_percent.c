/*
** EPITECH PROJECT, 2025
** handle percent
** File description:
** make flag %%
*/

#include "includes/my.h"
#include <stdarg.h>

void handle_percent(va_list args, int *count)
{
    (void)args;
    my_putchar('%', count);
}
