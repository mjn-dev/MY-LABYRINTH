/*
** EPITECH PROJECT, 2025
** my
** File description:
** insert_after
*/

#include "includes/linked_list.h"
#include "../libmy/includes/my.h"

void insert_after(node_t *prevNode, void *data)
{
    node_t *new_node = NULL;

    if (prevNode == NULL) {
        my_printf("Le nœud précédent ne peut pas être NULL\n");
        return;
    }
    new_node = create_node(data);
    new_node->next = prevNode->next;
    prevNode->next = new_node;
}
