/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** print_debug
*/

#include "my.h"
#include "linked_list.h"
#include "amazed.h"

void print_link(void *data)
{
    link_t *link;

    link = (link_t *)data;
    my_printf("%s-%s\n",
        link->room_1->name,
        link->room_2->name);
}

void print_robot(void *data)
{
    robot_t *robot;

    robot = (robot_t *)data;
    my_printf("robot: %d \n", robot->id);
}

void print_room(void *data)
{
    room_t *room;

    room = (room_t *)data;
    if (room->is_start){
        my_printf("##start\n");
    }
    if (room->is_end){
        my_printf("##end\n");
    }
    my_printf("%s %d %d\n",
        room->name,
        room->x,
        room->y);
}

void print_movement(movement_t *movement)
{
    my_printf("P%d-%s ", movement->robot_id, movement->room_name);
}

void print_robot_count(int robot_count)
{
    my_printf("#number_of_robot\n");
    my_printf("%d\n", robot_count);
    my_printf("#rooms\n");
}
