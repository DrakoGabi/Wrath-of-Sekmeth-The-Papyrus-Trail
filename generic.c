/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** generic
*/

#include "rpg.h"

int next_message(base_t *b, int i)
{
    float t = sfTime_asSeconds(sfClock_getElapsedTime(b->fstate.player->cl));

    if (t <= 2)
        return i;
    sfClock_restart(b->fstate.player->cl);
    if (gen[i + 1])
        sfText_setString(b->fstate.ent.ent, gen[i + 1]);
    return i + 1;
}

void generic_setup(base_t *b)
{
    stop_combat_music(b);
    replace_sp_tex(GEN_BG, &b->fstate.bg);
    set_sp_scale((sfVector2f){2.7, 2.8}, &b->fstate.bg);
    sfView_setCenter(b->pov, (sfVector2f){1920 / 2, 1080 / 2});
    sfView_setSize(b->pov, (sfVector2f){(1920), (1080)});
    sfRenderWindow_setView(b->win, b->pov);
    sfClock_restart(b->fstate.player->cl);
    sfText_setFillColor(b->fstate.ent.ent, sfBlack);
    sfText_setPosition(b->fstate.ent.ent, (sfVector2f){770, 400});
    sfMusic_play(b->ge_mus);
    sfText_setFont(b->fstate.ent.ent, b->font);
}

void win(base_t *b)
{
    int i = 0;

    generic_setup(b);
    sfText_setString(b->fstate.ent.ent, gen[i]);
    for (; sfRenderWindow_isOpen(b->win) && gen[i];) {
        handle_event(b);
        sfRenderWindow_clear(b->win, sfBlack);
        draw_sprite(b->win, b->fstate.bg);
        sfRenderWindow_drawText(b->win, b->fstate.ent.ent, NULL);
        i = next_message(b, i);
        sfRenderWindow_display(b->win);
    }
    sfMusic_stop(b->ge_mus);
    return_to_menu(b);
}
