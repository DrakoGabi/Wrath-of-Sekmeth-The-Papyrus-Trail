/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** overworld
*/

#include "rpg.h"

void handle_event(base_t *base)
{
    while (sfRenderWindow_pollEvent(base->win, &base->evt)) {
        if (base->evt.type == sfEvtClosed ||
        just_pressed(base, sfKeyEscape))
            sfRenderWindow_close(base->win);
        apply_button(base, &base->menu.start);
        apply_button(base, &base->menu.setting);
    }
}

void draw_overworld(base_t *base)
{
    draw_sprite(base->win, base->map.sp);
    draw_all_npc(base);
    draw_sprite(base->win, base->input);
    draw_sprite(base->win, base->player.map.sp);
}

void overworld(base_t *b)
{
    sfRenderWindow_setView(b->win, b->pov);
    set_sp_pos((sfVector2f){620, 1500}, &b->player.map.sp);
    sfMusic_play(b->over_mus);
    while (sfRenderWindow_isOpen(b->win) && b->player.alive && b->thot.alive) {
        handle_event(b);
        sfRenderWindow_clear(b->win, (sfColor){214, 160, 84, 255});
        check_pause(b);
        draw_overworld(b);
        activate_bosses(b);
        handle_move(b);
        sfRenderWindow_display(b->win);
    }
    sfMusic_stop(b->over_mus);
    if (!b->thot.alive)
        win(b);
}
