/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** fill struct for robot
*/

#include "my.h"
#include "linked_list.h"
#include "amazed.h"

int compare_room_bool(void *data, void *key)
{
    room_t *room = (room_t *)data;
    bool start = (bool *)key;

    return room->is_start == start ? EXIT_S : EXIT_F;
}

int parse_robot(int robot_count, node_t **room_list, node_t **robot_list)
{
    robot_t *current_robot = NULL;
    node_t *put_current = NULL;

    for (int i = 1; i != robot_count + 1; i++) {
        current_robot = malloc(sizeof(robot_t));
        if (current_robot == NULL)
            return my_putstr_err("Error when allocating robot node\n", EXIT_F);
        current_robot->id = i;
        put_current = search(*room_list, TRUE, compare_room_bool);
        if (put_current == NULL){
            free(current_robot);
            return EXIT_F;
        }
        current_robot->current_room = (room_t *)put_current->data;
        insert_at_end(robot_list, current_robot);
    }
    return EXIT_S;
}
