/*
** EPITECH PROJECT, 2025
** my_strncmp.c
** File description:
** just compare n character of two strings
*/

#include <stdio.h>
#include <string.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    if (i < n) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        i++;
    }
    return 0;
}
/*
int main(void)
{
    char str1[] = "Hell";
    char str2[] = "Helo";
    int n = 5;
    int result = my_strncmp(str1, str2, n);

    if (result == 0) {
        my_printf("Indentique");
    } else if (result < 0) {
        my_printf("str1 < str2");
    } else {
        my_printf("str1 > str2");
    }
    return 0;
}
*/
