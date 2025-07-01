/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** main
*/

#include "my.h"
#include "linked_list.h"
#include "amazed.h"

int main(void)
{
    AUTOFREE_LIST node_t *room_list = NULL;
    AUTOFREE_LIST node_t *link_list = NULL;
    AUTOFREE_LIST node_t *robot_list = NULL;
    path_t **paths = NULL;
    char **line = read_lines_from_stdin();

    if (line == NULL)
        return EXIT_F;
    if (parsing(line, &room_list, &link_list, &robot_list) == EXIT_F)
        return EXIT_F;
    paths = find_paths_for_robots(robot_list, room_list, link_list);
    if (!paths)
        return EXIT_F;
    execute_movements(robot_list, paths);
    return EXIT_S;
}
