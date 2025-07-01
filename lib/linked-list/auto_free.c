/*
** EPITECH PROJECT, 2025
** linked-list
** File description:
** auto_free
*/

#include "includes/linked_list.h"

void autofree_list(node_t **head)
{
    if (head && *head) {
        free_list(*head, free);
        *head = NULL;
    }
}
