/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** inv_button
*/

#include "rpg.h"

inv_button_t create_inv_button(void)
{
    inv_button_t res = {0};

    res.bdg.square = sfRectangleShape_create();
    res.dring.square = sfRectangleShape_create();
    res.sring.square = sfRectangleShape_create();
    res.dring.state = true;
    res.sring.state = true;
    sfRectangleShape_setSize(res.bdg.square, (sfVector2f){30, 30});
    sfRectangleShape_setSize(res.dring.square, (sfVector2f){30, 30});
    sfRectangleShape_setSize(res.sring.square, (sfVector2f){30, 30});
    sfRectangleShape_setFillColor(res.bdg.square, sfRed);
    sfRectangleShape_setFillColor(res.dring.square, sfGreen);
    sfRectangleShape_setFillColor(res.sring.square, sfGreen);
    sfRectangleShape_setPosition(res.bdg.square, (sfVector2f){600, 720});
    sfRectangleShape_setPosition(res.dring.square, (sfVector2f){670, 910});
    sfRectangleShape_setPosition(res.sring.square, (sfVector2f){660, 830});
    res.bdg.visible = true;
    return res;
}

void destroy_inv_button(inv_button_t res)
{
    sfRectangleShape_destroy(res.dring.square);
    sfRectangleShape_destroy(res.sring.square);
    sfRectangleShape_destroy(res.bdg.square);
}

void draw_square(sfRenderWindow *win, square_button_t res)
{
    if (res.visible)
        sfRenderWindow_drawRectangleShape(win, res.square, NULL);
}
