/*
** EPITECH PROJECT, 2025
** includes/flag.h
** File description:
** contain struc end prototype
*/

#include <stdarg.h>
#include <stddef.h>

#ifndef FLAG_H_
    #define FLAG_H_

void handle_char(va_list args, int *count);
void handle_int(va_list args, int *count);
void handle_str(va_list args, int *count);
void handle_percent(va_list args, int *count);
void handle_oct(va_list args, int *count);
void handle_hex(va_list args, int *count);
void handle_min_hex(va_list args, int *count);
void handle_u(va_list args, int *count);
void handle_float(va_list args, int *count);
void handle_n(va_list args, int *count);
void handle_p(va_list args, int *count);
void handle_scient(va_list args, int *count);

struct function_pointer {
    char flag;
    void (*pt)(va_list args, int *count);
};

static const struct function_pointer handle_flag[] = {
    {'c', &handle_char},
    {'i', &handle_int},
    {'d', &handle_int},
    {'s', &handle_str},
    {'%', &handle_percent},
    {'o', &handle_oct},
    {'X', &handle_hex},
    {'x', &handle_min_hex},
    {'u', &handle_u},
    {'f', &handle_float},
    {'n', &handle_n},
    {'p', &handle_p},
    {'e', &handle_scient},
    {'\0', NULL},
};

#endif /* FLAG_H_ */
