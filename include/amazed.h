/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** amazed
*/
#ifndef AMAZED_H
	#define AMAZED_H
	#define MAX_LINES 1024
	#define EXIT_F 84
	#define EXIT_S 0
	#define NOT_NULL ((void *)1)
	#define FB false
	#define TB true
	#define TRUE "true"
	#define FALSE "false"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>
	#include <fcntl.h>
	#include <unistd.h>
	#include "linked_list.h"

// Structure pour une salle
typedef struct room_s {
    char *name;
    int x;
    int y;
    bool is_start;
    bool is_end;
} room_t;

typedef struct link_s {
    room_t *room_1;
    room_t *room_2;
} link_t;

typedef struct queue_node_s {
    room_t *room;
    struct queue_node_s *next;
    struct queue_node_s *parent;
} queue_node_t;

typedef struct robot_s {
    int id;
    room_t *current_room;
} robot_t;

typedef struct path_s {
    room_t **rooms;
    int length;
} path_t;

typedef struct movement_context_s {
    path_t **paths;
    int *current_positions;
    node_t *robot_list;
    room_t *end_room;
} movement_context_t;

typedef struct robot_state_s {
    bool *finished;
    bool *moved;
    movement_context_t *context;
} robot_state_t;

typedef struct {
    int robot_id;
    char *room_name;
} movement_t;

void print_room(void *data);
void print_link(void *data);
void print_robot_count(int robot_count);
int my_putstr_err(char const *str, int rtv);
int add_link(char *line, node_t **link_list, node_t *room_list);
void sanitize_names(char *name_1, char *name_2);
void *add_room(char *line, node_t **room_list, bool start, bool end);
char **read_lines_from_stdin(void);
int parsing(char **line, node_t **room_list, node_t **link_list,
    node_t **robot_lsit);
int parse_robot(int robot_count, node_t **room_list, node_t **robot_list);
int compare_room_bool(void *data, void *key);

void execute_movements(node_t *robot_list, path_t **paths);

path_t **find_paths_for_robots(node_t *robot_list, node_t *room_list,
    node_t *link_list);
room_t **get_neighbors(room_t *room, node_t *link_list, int *count);
path_t *reconstruct_path(room_t *start, room_t *end, queue_node_t *last_node);


queue_node_t *create_queue_node(room_t *room, queue_node_t *parent);
bool init_bfs(queue_node_t **queue, bool **visited,
    room_t *start, node_t *room_list);
path_t *reconstruct_path(room_t *start, room_t *end, queue_node_t *last_node);
room_t **get_neighbors(room_t *room, node_t *link_list, int *count);

void print_movement(movement_t *movement);
#endif /* AMAZED_H */
