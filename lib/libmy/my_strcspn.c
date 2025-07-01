/*
** EPITECH PROJECT, 2025
** B-MUL-100-PAR-1-1-myradar-philibert.gentien
** File description:
** Returns the length of the largest substring (starting from the beginning
** of the initial string) containing none of the characters specified in the
** list of rejected characters.
*/

#include "includes/my.h"
#include <stddef.h>

size_t my_strcspn(const char *s, const char *reject)
{
    size_t count = 0;
    char *found;

    for (; *s != '\0'; ++s) {
        found = my_strchr(reject, *s);
        if (found != NULL)
            return count;
        ++count;
    }
    return count;
}
