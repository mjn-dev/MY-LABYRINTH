/*
** EPITECH PROJECT, 2025
** my
** File description:
** delete_node
*/

#include "includes/linked_list.h"


void delete_node(node_t **head, void *key,
    int (*compare)(void *, void *),
    void (*destroy_data)(void *))
{
    node_t *temp = *head;
    node_t *prev = NULL;

    if (temp != NULL && compare(temp->data, key) == 0) {
        *head = temp->next;
        if (destroy_data)
            destroy_data(temp->data);
        free(temp);
        return;
    }
    while (temp != NULL && compare(temp->data, key) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    if (destroy_data)
        destroy_data(temp->data);
    free(temp);
}
