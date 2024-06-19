/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** mouvement
*/

#include "rpg.h"

void move_up(base_t *b)
{
    sfVector2f up = {0, -3};
    sfVector2f pos = get_pos(0, b->player.map.sp);
    int x = pos.x / 16;
    int y = (pos.y -3) / 16;
    int index = (int)(x + y * (int)(b->map.height));
    int x2 = (pos.x + L_FRONT) / 16;
    int index2 = (int)(x2 + y * (int)(b->map.height));

    flip((sfVector2f){1, 1}, L_FRONT, &b->player.map);
    if (b->map.layers.indexes[index] == 1
    || b->map.layers.indexes[index2] == 1)
        return;
    sp_move(b->player.map.sp, up.x, up.y);
    sfView_move(b->pov, up);
    sfRenderWindow_setView(b->win, b->pov);
}

void move_down(base_t *b)
{
    sfVector2f down = {0, +3};
    sfVector2f pos = get_pos(1, b->player.map.sp);
    int x = pos.x / 16;
    int y = (pos.y + L_FRONT + 3) / 16;
    int x2 = (pos.x + L_FRONT) / 16;
    int index = (int)(x + y * (int)(b->map.height));
    int index2 = (int)(x2 + y * (int)(b->map.height));

    flip((sfVector2f){1, -1}, L_FRONT, &b->player.map);
    if (b->map.layers.indexes[index] == 1 ||
        b->map.layers.indexes[index2] == 1)
        return;
    sp_move(b->player.map.sp, down.x, down.y);
    sfView_move(b->pov, down);
    sfRenderWindow_setView(b->win, b->pov);
}

void move_left(base_t *b)
{
    sfVector2f left = {-3, 0};
    sfVector2f pos = get_pos(2, b->player.map.sp);
    int x = (pos.x -3) / 16;
    int y = pos.y / 16;
    int y2 = (pos.y + L_SIDE) / 16;
    int index2 = (int)(x + y2 * (int)(b->map.width));
    int index = (int)(x + y * (int)(b->map.width));

    flip((sfVector2f){1, 1}, L_SIDE, &b->player.map);
    if (b->map.layers.indexes[index] == 1 ||
        b->map.layers.indexes[index2] == 1)
        return;
    sp_move(b->player.map.sp, left.x, left.y);
    sfView_move(b->pov, left);
    sfRenderWindow_setView(b->win, b->pov);
}

void move_right(base_t *b)
{
    sfVector2f right = {+3, 0};
    sfVector2f pos = get_pos(3, b->player.map.sp);
    int x = (pos.x + L_SIDE + 3) / 16;
    int y = pos.y / 16;
    int index = (int)(x + y * (int)(b->map.width));
    int y2 = (pos.y + L_SIDE) / 16;
    int index2 = (int)(x + y2 * (int)(b->map.width));

    flip((sfVector2f){-1, 1}, L_SIDE, &b->player.map);
    if (b->map.layers.indexes[index] == 1 ||
        b->map.layers.indexes[index2] == 1)
        return;
    sp_move(b->player.map.sp, right.x, right.y);
    sfView_move(b->pov, right);
    sfRenderWindow_setView(b->win, b->pov);
}

void handle_move(base_t *base)
{
    int i = 0;

    collide_all_npc(base);
    collide_npc_input(base);
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        move_up(base);
        i++;
    } else if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        move_down(base);
        i++;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && i == 0) {
        return move_left(base);
        i++;
    } else if (sfKeyboard_isKeyPressed(sfKeyRight) && i == 0) {
        move_right(base);
        i++;
    }
    if (i >= 1)
        are_you_fighting(base);
}
