/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** path_utils
*/

#include "amazed.h"
#include "my.h"

static int count_nodes(room_t *start, queue_node_t *last)
{
    queue_node_t *curr = last;
    int len = 0;

    if (!start || !last)
        return 0;
    while (curr) {
        len++;
        if (curr->room == start)
            return len;
        curr = curr->parent;
    }
    return 0;
}

static void set_rooms(path_t *path, queue_node_t *last)
{
    queue_node_t *curr = last;
    int i = path->length - 1;

    while (curr && i >= 0) {
        path->rooms[i] = curr->room;
        curr = curr->parent;
        i--;
    }
}

path_t *reconstruct_path(room_t *start, room_t *end, queue_node_t *last)
{
    path_t *path = malloc(sizeof(path_t));

    (void)end;
    if (!path || !start || !last)
        return NULL;
    path->length = count_nodes(start, last);
    if (path->length < 2) {
        free(path);
        return NULL;
    }
    path->rooms = malloc(sizeof(room_t *) * path->length);
    if (!path->rooms) {
        free(path);
        return NULL;
    }
    set_rooms(path, last);
    return path;
}
