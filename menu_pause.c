/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** menu_pause
*/

#include "rpg.h"

ingame_t create_pause(sfFont *font)
{
    ingame_t res = {0};

    res.save = create_sheets(SAVE, 98);
    res.inv = create_sheets(INV, 98);
    res.stats = create_sheets(STATS, 98);
    res.st = create_sprite(ZONE);
    set_sp_scale((sfVector2f){2, 3}, &res.save.sp);
    set_sp_scale((sfVector2f){2, 3}, &res.inv.sp);
    set_sp_scale((sfVector2f){2, 3}, &res.stats.sp);
    set_sp_pos((sfVector2f){700, 700}, &res.inv.sp);
    set_sp_scale((sfVector2f){2, 5}, &res.st);
    set_sp_pos((sfVector2f){540, 700}, &res.st);
    set_sp_pos((sfVector2f){700, 750}, &res.save.sp);
    set_sp_pos((sfVector2f){700, 800}, &res.stats.sp);
    res.st.visible = false;
    res.txt = set_text("o", font, sfBlack);
    set_pause_ani(&res);
    res.buttons = create_inv_button();
    return res;
}

void draw_pause(sfRenderWindow *win, ingame_t pause)
{
    draw_sprite(win, pause.save.sp);
    draw_sprite(win, pause.inv.sp);
    draw_sprite(win, pause.stats.sp);
    draw_sprite(win, pause.st);
    if (pause.st.visible)
        sfRenderWindow_drawText(win, pause.txt, NULL);
    if (pause.buttons.visible) {
        draw_square(win, pause.buttons.bdg);
        draw_square(win, pause.buttons.dring);
        draw_square(win, pause.buttons.sring);
    }
}

void destroy_pause(ingame_t pause)
{
    destroy_sheets(pause.save);
    destroy_sheets(pause.stats);
    destroy_sheets(pause.inv);
    destroy_sprite(pause.st);
    sfText_destroy(pause.txt);
    destroy_inv_button(pause.buttons);
}

void pause_loop(base_t *b)
{
    sfVector2f p = get_sp_pos(b->player.map.sp);

    while (!just_pressed(b, sfKeyTab) && sfRenderWindow_isOpen(b->win)) {
        sfRenderWindow_clear(b->win, (sfColor){214, 160, 84, 255});
        handle_event_pause(b);
        draw_overworld(b);
        draw_pause(b->win, b->pause);
        sfRenderWindow_display(b->win);
    }
    sfView_setCenter(b->pov, p);
    sfView_setSize(b->pov, (sfVector2f){(30 * 16), (20 * 16)});
    sfRenderWindow_setView(b->win, b->pov);
}

void check_pause(base_t *base)
{
    if (just_pressed(base, sfKeyTab)) {
        sfView_setCenter(base->pov, (sfVector2f){1600 / 2, 1600 / 2});
        sfView_setSize(base->pov, (sfVector2f){(1600), (1600)});
        sfRenderWindow_setView(base->win, base->pov);
        pause_loop(base);
    }
}
