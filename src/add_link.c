/*
** EPITECH PROJECT, 2025
** add list
** File description:
** complete strcut list
*/

#include "my.h"
#include "linked_list.h"
#include "amazed.h"

static int compare_room_name(void *data, void *key)
{
    room_t *room = (room_t *)data;
    char *name = (char *)key;

    return my_strcmp(room->name, name);
}

void sanitize_names(char *name_1, char *name_2)
{
    for (int i = 0; name_1[i]; i++)
        if (name_1[i] == '\n' || name_1[i] == ' ')
            name_1[i] = '\0';
    for (int i = 0; name_2[i]; i++)
        if (name_2[i] == '\n' || name_2[i] == ' ')
            name_2[i] = '\0';
}

static int extract_room_names(char *line, char **name_1, char **name_2)
{
    if (!line)
        return EXIT_F;
    *name_1 = my_strtok(line, "-");
    *name_2 = my_strtok(NULL, "-");
    if (!*name_1 || !*name_2)
        return EXIT_F;
    sanitize_names(*name_1, *name_2);
    return EXIT_S;
}

int add_link(char *line, node_t **link_list, node_t *room_list)
{
    link_t *link = malloc(sizeof(link_t));
    char *line_copy = my_strdup(line);
    char *name_1 = NULL;
    char *name_2 = NULL;
    node_t *room_1 = NULL;
    node_t *room_2 = NULL;

    if (link_list == NULL || room_list == NULL || line == NULL ||
        link == NULL || line_copy == NULL)
        return free_and_null(EXIT_F, line_copy, link);
    if (extract_room_names(line_copy, &name_1, &name_2) == EXIT_F)
        return free_and_null(EXIT_F, link, line_copy);
    room_1 = search(room_list, name_1, compare_room_name);
    room_2 = search(room_list, name_2, compare_room_name);
    if (!room_1 || !room_2)
        return free_and_null(EXIT_F, link, line_copy);
    link->room_1 = (room_t *)room_1->data;
    link->room_2 = (room_t *)room_2->data;
    insert_at_end(link_list, link);
    return free_and_null(EXIT_S, line_copy);
}
