/*
** EPITECH PROJECT, 2025
** my
** File description:
** insert_at_position
*/

#include "includes/linked_list.h"
#include "../libmy/includes/my.h"

void insert_at_position(node_t **head, void *data, int position)
{
    node_t *temp = NULL;

    if (position == 0) {
        insert_at_beginning(head, data);
        return;
    }
    temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        my_printf("La position est hors de la liste\n");
        return;
    }
    insert_after(temp, data);
}
