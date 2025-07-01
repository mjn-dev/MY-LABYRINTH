/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** frees
*/

#include "amazed.h"

void free_room(void *data)
{
    room_t *room = (room_t *)data;

    free(room->name);
    free(room);
}

void free_room(void *data)
{
    room_t *room = (room_t *)data;

    free(room->name);
    free(room);
}

void free_path(void *data)
{
    path_t *path = (path_t *)data;

    if (path) {
        free(path->rooms);
        free(path);
    }
}
