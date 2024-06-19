/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** settings
*/

#include "rpg.h"

void handleset_event(base_t *base)
{
    while (sfRenderWindow_pollEvent(base->win, &base->evt)) {
        if (base->evt.type == sfEvtClosed ||
        just_pressed(base, sfKeyEscape))
            sfRenderWindow_close(base->win);
        apply_button(base, &base->menu.back);
        apply_button(base, &base->menu.control);
    }
}

void draw_setting(sfRenderWindow *win, menu_t menu)
{
    draw_sprite(win, menu.bg);
    draw_sprite(win, menu.back.icon.sp);
    draw_sprite(win, menu.control.icon.sp);
}

void setting_loop(base_t *b)
{
    for (; sfRenderWindow_isOpen(b->win);) {
        handleset_event(b);
        sfRenderWindow_clear(b->win, sfBlack);
        draw_setting(b->win, b->menu);
        anime_button(&b->menu.back);
        anime_button(&b->menu.control);
        sfRenderWindow_display(b->win);
        if (b->menu.playable == b->menu.back.value)
            break;
        if (b->menu.playable == b->menu.control.value)
            control_loop(b);
    }
}
