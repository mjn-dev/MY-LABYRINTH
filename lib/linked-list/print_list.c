/*
** EPITECH PROJECT, 2025
** my
** File description:
** print_list
*/

#include "includes/linked_list.h"

void print_list(node_t *head, void (*printData)(void *))
{
    node_t *temp = head;

    while (temp != NULL) {
        printData(temp->data);
        temp = temp->next;
    }
}
