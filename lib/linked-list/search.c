/*
** EPITECH PROJECT, 2025
** my
** File description:
** search
*/

#include "includes/linked_list.h"

node_t *search(node_t *head, void *key,
    int (*compare)(void *, void *))
{
    node_t *temp = head;

    while (temp != NULL) {
        if (compare(temp->data, key) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
