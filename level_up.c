/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** level_up
*/

#include "rpg.h"

void level_up(base_t *b)
{
    if (b->player.stats.lvl >= 20) {
        b->player.stats.lvl = 20;
        b->exp = 0;
        return;
    }
    if (b->exp >= 100) {
        b->exp -= 100;
        set_level(b->player.stats.lvl + 1, &b->player.stats, 0);
    }
    if (b->player.stats.lvl >= 8)
        b->fstate.spell[1].bg.visible = true;
    if (b->player.stats.lvl >= 5)
        b->npc[1].alive = false;
}

void return_to_menu(base_t *b)
{
    set_sp_scale((sfVector2f){2, 2.4}, &b->fstate.bg);
    sfText_setPosition(b->fstate.ent.ent, (sfVector2f){900, 500});
    sfText_setFillColor(b->fstate.ent.ent, sfGreen);
    sfMusic_stop(b->go_mus);
    b->menu.playable = false;
    save_recup(b);
    b->thot.alive = true;
    for (int i = 0; i < 5; i++)
        b->npc[i].alive = true;
    menu_loop(b);
}

void die(base_t *b)
{
    stop_combat_music(b);
    sfMusic_play(b->go_mus);
    replace_sp_tex(GAMEOVER, &b->menu.bg);
    sfView_setCenter(b->pov, (sfVector2f){1920 / 2, 1080 / 2});
    sfView_setSize(b->pov, (sfVector2f){(1920), (1080)});
    sp_texture_rect((sfIntRect){0, 0, 697, 392}, &b->menu.bg);
    set_sp_scale((sfVector2f){2.8, 2.8}, &b->menu.bg);
    sfRenderWindow_setView(b->win, b->pov);
    for (; sfRenderWindow_isOpen(b->win);) {
        handle_event(b);
        sfRenderWindow_clear(b->win, sfBlack);
        draw_sprite(b->win, b->menu.bg);
        draw_sprite(b->win, b->press);
        sfRenderWindow_display(b->win);
        if (just_pressed(b, sfKeyEnter))
            break;
    }
    return_to_menu(b);
}
