/*
** EPITECH PROJECT, 2025
** my
** File description:
** reverse_list
*/

#include "includes/linked_list.h"

void reverse_list(node_t **head)
{
    node_t *prev = NULL;
    node_t *current = *head;
    node_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
