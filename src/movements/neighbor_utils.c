/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** neighbor_utils
*/

#include "amazed.h"

static void add_neighbor(room_t **neighbors, room_t *room, int *count)
{
    neighbors[*count] = room;
    (*count)++;
}

static void check_link(link_t *link, room_t *room, room_t **neighbors,
    int *count)
{
    if (link->room_1 == room)
        add_neighbor(neighbors, link->room_2, count);
    if (link->room_2 == room)
        add_neighbor(neighbors, link->room_1, count);
}

room_t **get_neighbors(room_t *room, node_t *link_list, int *count)
{
    node_t *current = link_list;
    room_t **neighbors = malloc(sizeof(room_t *) * get_length(link_list));
    link_t *link = NULL;

    *count = 0;
    if (!neighbors)
        return NULL;
    while (current) {
        link = (link_t *)current->data;
        check_link(link, room, neighbors, count);
        current = current->next;
    }
    return neighbors;
}
