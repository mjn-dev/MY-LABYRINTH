/*
** EPITECH PROJECT, 2025
** my
** File description:
** create_node
*/

#include "includes/linked_list.h"

node_t *create_node(void *data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
