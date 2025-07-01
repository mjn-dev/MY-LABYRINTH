/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** free_queue
*/

#include "amazed.h"
#include "my.h"

void free_queue(queue_node_t *queue)
{
    queue_node_t *current = NULL;

    while (queue) {
        current = queue;
        queue = queue->next;
        free(current);
    }
}
