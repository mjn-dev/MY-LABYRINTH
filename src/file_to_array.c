/*
** EPITECH PROJECT, 2025
** file_to_array.c
** File description:
** file_to_array
*/

#include "my.h"
#include "amazed.h"

char **read_lines_from_stdin(void)
{
    char **lines = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read = -1;
    int i = 0;

    lines = malloc(sizeof(char *) * (MAX_LINES + 1));
    if (lines == NULL)
        return NULL;
    while (getline(&line, &len, stdin) != -1 && i < MAX_LINES) {
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';
        lines[i] = my_strdup(line);
        i++;
    }
    free(line);
    lines[i] = NULL;
    return lines;
}
