/*
** EPITECH PROJECT, 2025
** my_printf
** File description:
** printf with pointeur of function
*/

#include "includes/my.h"
#include "includes/flag.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

static void which_flag(const char *format, int index, va_list args, int *count)
{
    char flag = format[index];

    for (int n = 0; handle_flag[n].flag != '\0'; n++) {
        if (handle_flag[n].flag == flag)
            handle_flag[n].pt(args, count);
    }
}

int my_printf(char const *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            which_flag(format, i, args, &count);
        } else {
            my_putchar(format[i], &count);
        }
    }
    va_end(args);
    return count;
}
