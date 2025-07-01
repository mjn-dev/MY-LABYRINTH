/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-amazed-philibert.gentien
** File description:
** execute_movements
*/

#include "amazed.h"
#include "my.h"

static bool check_inputs(node_t *list, path_t **paths, int *pos)
{
    if (!pos || !list || !paths) {
        free(pos);
        return false;
    }
    return true;
}

static room_t *find_end(node_t *list, path_t **paths)
{
    node_t *curr = list;
    robot_t *robot;
    path_t *path = NULL;

    while (curr) {
        robot = curr->data;
        path = paths[robot->id - 1];
        if (path && path->length > 0)
            return path->rooms[path->length - 1];
        curr = curr->next;
    }
    return NULL;
}

static bool is_room_free(node_t *list, room_t *room, int id, room_t *end)
{
    node_t *curr = list;
    robot_t *robot;

    if (room == end)
        return true;
    while (curr) {
        robot = curr->data;
        if (robot->id != id && robot->current_room == room)
            return false;
        curr = curr->next;
    }
    return true;
}

static void move_robot(robot_t *robot, room_t *next, int *pos)
{
    movement_t mov = {robot->id, next->name};

    robot->current_room = next;
    print_movement(&mov);
    (*pos)++;
}

static bool get_next_room(robot_t *robot, movement_context_t *ctx,
    room_t **next)
{
    int pos = ctx->current_positions[robot->id - 1];

    if (!ctx->paths[robot->id - 1] || ctx->paths[robot->id - 1]->length <= 1)
        return false;
    if (pos >= ctx->paths[robot->id - 1]->length - 1)
        return false;
    *next = ctx->paths[robot->id - 1]->rooms[pos + 1];
    return *next != NULL;
}

static bool process_move(robot_t *robot, movement_context_t *ctx)
{
    room_t *next;

    if (robot->current_room == ctx->end_room)
        return true;
    if (!get_next_room(robot, ctx, &next))
        return false;
    if (is_room_free(ctx->robot_list, next, robot->id, ctx->end_room)) {
        move_robot(robot, next, &ctx->current_positions[robot->id - 1]);
        return next == ctx->end_room;
    }
    return false;
}

static void process_robot(robot_t *robot, bool *done, bool *moved,
    movement_context_t *ctx)
{
    bool robot_done = process_move(robot, ctx);

    *done = *done && robot_done;
    if (!robot_done)
        *moved = true;
}

static void loop_robots(node_t *list, bool *done, bool *moved,
    movement_context_t *ctx)
{
    node_t *curr = list;
    robot_t *robot;

    while (curr) {
        robot = curr->data;
        process_robot(robot, done, moved, ctx);
        curr = curr->next;
    }
}

static void run_loop(node_t *list, path_t **paths, int *pos, room_t *end)
{
    movement_context_t ctx = {paths, pos, list, end};
    bool done = false;
    bool moved;
    int lap = 0;

    my_printf("#moves\n");
    while (!done && lap < 1000) {
        done = true;
        moved = false;
        loop_robots(list, &done, &moved, &ctx);
        if (moved)
            my_printf("\n");
        if (!moved && done)
            break;
        lap++;
    }
}

void execute_movements(node_t *robot_list, path_t **paths)
{
    int *pos = my_calloc(get_length(robot_list), sizeof(int));
    room_t *end;

    if (!check_inputs(robot_list, paths, pos))
        return;
    end = find_end(robot_list, paths);
    if (!end) {
        free(pos);
        return;
    }
    run_loop(robot_list, paths, pos, end);
    my_printf("\n");
    free(pos);
}
