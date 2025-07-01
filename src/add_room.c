/*
** EPITECH PROJECT, 2025
** complete_struct
** File description:
** fill all struct
*/

#include "my.h"
#include "linked_list.h"
#include "amazed.h"

void *error_handling(room_t *room, int error)
{
    if (room->name == NULL || error == 84)
        return NULL;
    return NOT_NULL;
}

static bool parse_coordinates(int *x, int *y)
{
    int error = -1;

    *x = my_getnbr_parsing(my_strtok(NULL, " \n"), &error);
    if (error == 84)
        return false;
    *y = my_getnbr_parsing(my_strtok(NULL, " \n"), &error);
    return (error != 84);
}

void *add_room(char *line, node_t **room_list, bool start, bool end)
{
    room_t *room = malloc(sizeof(room_t));
    int x = 0;
    int y = 0;

    if (line == NULL || room == NULL)
        return NULL;
    room->name = my_strdup(my_strtok(line, " "));
    if (!parse_coordinates(&x, &y) || error_handling(room, -1) == NULL)
        return NULL;
    room->x = x;
    room->y = y;
    room->is_start = start;
    room->is_end = end;
    print_room(room);
    insert_at_end(room_list, room);
    return NOT_NULL;
}
