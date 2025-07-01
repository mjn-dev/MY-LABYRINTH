/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** bfs
*/

#include "amazed.h"
#include "my.h"

static void add_neighbor(queue_node_t **queue, room_t *room,
    queue_node_t *parent, bool *visited)
{
    queue_node_t *node = create_queue_node(room, parent);

    if (!node || visited[my_getnbr(room->name)])
        return;
    visited[my_getnbr(room->name)] = true;
    node->next = *queue;
    *queue = node;
}

static void handle_neighbors(queue_node_t *cur, node_t *links,
    queue_node_t **queue, bool *visited)
{
    room_t **neigh = NULL;
    int count = 0;

    neigh = get_neighbors(cur->room, links, &count);
    for (int i = 0; neigh && i < count; i++)
        add_neighbor(queue, neigh[i], cur, visited);
    free(neigh);
}

path_t *bfs(room_t *start, node_t *links, node_t *rooms)
{
    queue_node_t *queue = NULL;
    queue_node_t *cur = NULL;
    bool *visited = NULL;
    path_t *path = NULL;

    if (!init_bfs(&queue, &visited, start, rooms))
        return NULL;
    while (queue) {
        cur = queue;
        queue = queue->next;
        if (cur->room->is_end) {
            path = reconstruct_path(start, NULL, cur);
            break;
        }
        handle_neighbors(cur, links, &queue, visited);
    }
    free(visited);
    return path;
}

path_t **find_paths_for_robots(node_t *robot_list, node_t *room_list,
    node_t *link_list)
{
    int count = get_length(robot_list);
    path_t **paths = malloc(sizeof(path_t *) * count);
    node_t *curr = robot_list;
    robot_t *robot = NULL;

    if (!paths)
        return NULL;
    for (int i = 0; i < count && curr; i++) {
        robot = curr->data;
        paths[i] = bfs(robot->current_room, link_list, room_list);
        curr = curr->next;
    }
    return paths;
}
