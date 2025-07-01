/*
** EPITECH PROJECT, 2025
** parsing
** File description:
** open file
*/

#include "my.h"
#include "linked_list.h"
#include "amazed.h"
#include "errors.h"

static bool handle_room_flags(char **line, int *i, bool *start, bool *end)
{
    if (my_strstr(line[*i], "##start")) {
        *start = true;
        return true;
    }
    if (my_strstr(line[*i], "##end")) {
        *end = true;
        return true;
    }
    return false;
}

static int parse_rooms(char **line, node_t **room_list, int *i)
{
    bool start = false;
    bool end = false;

    while (line[*i] != NULL) {
        if (handle_room_flags(line, i, &start, &end)) {
            (*i)++;
            continue;
        }
        if (my_strstr(line[*i], "# ") != NULL)
            (*i)++;
        if (my_strchr(line[*i], '-'))
            return EXIT_S;
        if (add_room(line[*i], room_list, start, end) == NULL)
            return EXIT_F;
        start = false;
        end = false;
        (*i)++;
    }
    return EXIT_S;
}

static int parse_links(char **line, node_t **link_list, node_t *room_list,
    int i)
{
    while (line[i] != NULL) {
        if (my_strstr(line[i], "# ") != NULL)
            i++;
        if (add_link(line[i], link_list, room_list) != EXIT_S)
            return EXIT_F;
        i++;
    }
    return EXIT_S;
}

int parsing(char **line, node_t **room_list, node_t **link_list,
    node_t **robot_list)
{
    int i = 1;
    int robot_count = my_getnbr(line[0]);

    print_robot_count(robot_count);
    if (parse_rooms(line, room_list, &i) == EXIT_F)
        return EXIT_F;
    if (parse_links(line, link_list, *room_list, i) == EXIT_F)
        return EXIT_F;
    if (parse_robot(robot_count, room_list, robot_list) == EXIT_F)
        return EXIT_F;
    my_printf("#tunnels\n");
    print_list(*link_list, print_link);
    return EXIT_S;
}
