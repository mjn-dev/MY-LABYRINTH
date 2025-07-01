/*
** EPITECH PROJECT, 2025
** my
** File description:
** free_list
*/

#include "includes/linked_list.h"

void free_list(node_t *head, void (*freeData)(void *))
{
    node_t *temp = NULL;

    while (head != NULL) {
        temp = head;
        head = head->next;
        if (freeData != NULL) {
            freeData(temp->data);
        }
        free(temp);
    }
}
