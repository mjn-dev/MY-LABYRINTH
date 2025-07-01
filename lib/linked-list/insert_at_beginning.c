/*
** EPITECH PROJECT, 2025
** my
** File description:
** insert_at_beginning
*/

#include "includes/linked_list.h"

void insert_at_beginning(node_t **head, void *data)
{
    node_t *new_node = create_node(data);

    new_node->next = *head;
    *head = new_node;
}
