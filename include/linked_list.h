/*
** EPITECH PROJECT, 2025
** includes/my.h header for my own lib
** File description:
** philibert's includes/my.h header
*/
#ifndef LINKED_LIST_H
    #define LINKED_LIST_H
    #include <stdio.h>
    #include <stdlib.h>
    #define AUTOFREE_LIST __attribute__((cleanup(autofree_list)))


typedef struct node_t {
    void *data;
    struct node_t *next;
} node_t;

node_t *create_node(void *data);
void insert_at_end(node_t **head, void *data);
void delete_node(node_t **head, void *key,
    int (*compare)(void *, void *),
    void (*destroy_data)(void *));
void print_list(node_t *head, void (*printData)(void *));
node_t *search(node_t *head, void *key,
    int (*compare)(void *, void *));
void free_list(node_t *head, void (*freeData)(void *));
void insert_at_beginning(node_t **head, void *data);
void insert_after(node_t *prevNode, void *data);
int get_length(node_t *head);
void insert_at_position(node_t **head, void *data, int position);
void reverse_list(node_t **head);
void autofree_list(node_t **head);

#endif /* LINKED_LIST_H */
