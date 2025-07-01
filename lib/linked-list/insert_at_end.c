/*
** EPITECH PROJECT, 2025
** my
** File description:
** insert_at_end
*/

#include "includes/linked_list.h"

void insert_at_end(node_t **head, void *data)
{
    node_t *new_node = create_node(data);
    node_t *temp = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}
