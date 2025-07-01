/*
** EPITECH PROJECT, 2025
** libs
** File description:
** free_multiples
*/

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

int free_and_null(int retval, ...)
{
    va_list args;
    void **ptr = NULL;

    va_start(args, retval);
    va_arg(args, void **);
    while (ptr != NULL) {
        if (*ptr != NULL) {
            free(*ptr);
            *ptr = NULL;
        }
    }
    va_end(args);
    return retval;
}
