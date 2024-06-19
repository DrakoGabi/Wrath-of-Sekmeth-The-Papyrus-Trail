/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** button
*/

#include "../include/rpg.h"

button_t create_button(char *path)
{
    button_t res = {0};

    res.icon = create_sheets(path, 128);
    res.base = sfRectangleShape_create();
    res.state = 1;
    return res;
}

void destroy_button(button_t but)
{
    destroy_sheets(but.icon);
    sfRectangleShape_destroy(but.base);
}
