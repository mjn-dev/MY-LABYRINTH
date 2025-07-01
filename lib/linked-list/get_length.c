/*
** EPITECH PROJECT, 2025
** my
** File description:
** get_length
*/

#include "includes/linked_list.h"

int get_length(node_t *head)
{
    int length = 0;
    node_t *temp = head;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}
