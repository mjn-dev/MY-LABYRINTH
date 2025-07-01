/*
** EPITECH PROJECT, 2025
** my_st_to_word_array.c
** File description:
** Philibert's str to word array function
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static int is_alphanum(char const c)
{
    if ((c >= 'A' && c <= 'Z')
        || (c >= 'a' && c <= 'z')
        || (c >= '0' && c <= '9'))
        return 1;
    return 0;
}

static int count_word(char const *str)
{
    int word_count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_alphanum(str[i])) {
            in_word = 0;
            continue;
        }
        if (!in_word) {
            in_word = 1;
            word_count++;
        }
    }
    return word_count;
}

static int count_letter(char const *str, int *i)
{
    int k = 0;

    while (str[*i] != '\0' && !is_alphanum(str[*i]))
        (*i)++;
    while (str[*i] != '\0' && is_alphanum(str[*i])) {
        k++;
        (*i)++;
    }
    return k;
}

char **my_str_to_word_array(char const *str)
{
    int letter_count = 0;
    int word_count = count_word(str);
    int index = 0;
    char **word_array = malloc(sizeof(char *) * (word_count + 1));

    if (!word_array)
        return NULL;
    for (int i = 0; i < word_count; i++) {
        letter_count = count_letter(str, &index);
        word_array[i] = malloc(sizeof(char) * (letter_count + 1));
        if (!word_array[i])
            return NULL;
        for (int p = 0; p < letter_count; p++) {
            word_array[i][p] = str[index - letter_count + p];
        }
        word_array[i][letter_count] = '\0';
    }
    word_array[word_count] = NULL;
    return word_array;
}
