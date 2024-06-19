/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** controls
*/

#include "rpg.h"

void draw_control(sfRenderWindow *win, menu_t menu)
{
    draw_sprite(win, menu.bg);
    draw_sprite(win, menu.back.icon.sp);
    draw_sprite(win, menu.input);
    draw_sprite(win, menu.moves);
}

void control_loop(base_t *b)
{
    for (; sfRenderWindow_isOpen(b->win);) {
        handleset_event(b);
        sfRenderWindow_clear(b->win, sfBlack);
        draw_control(b->win, b->menu);
        anime_button(&b->menu.back);
        sfRenderWindow_display(b->win);
        if (b->menu.playable == b->menu.back.value) {
            b->menu.playable = 0;
            break;
        }
    }
}
