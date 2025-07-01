/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** queue_utilis
*/

#include "amazed.h"
#include "my.h"

queue_node_t *create_queue_node(room_t *room, queue_node_t *parent)
{
    queue_node_t *node = malloc(sizeof(queue_node_t));

    if (!node)
        return NULL;
    node->room = room;
    node->next = NULL;
    node->parent = parent;
    return node;
}

bool init_bfs(queue_node_t **queue, bool **visited,
    room_t *start, node_t *room_list)
{
    *queue = create_queue_node(start, NULL);
    *visited = my_calloc(get_length(room_list), sizeof(bool));
    if (!queue || !*visited)
        return false;
    (*visited)[my_getnbr(start->name)] = true;
    return true;
}
