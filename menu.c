/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** menu
*/

#include "rpg.h"

void set_menu_scale(sfVector2f but_size, sfVector2f bg_size, menu_t *menu)
{
    set_sp_scale(but_size, &menu->start.icon.sp);
    set_sp_scale(but_size, &menu->setting.icon.sp);
    set_sp_scale(but_size, &menu->back.icon.sp);
    set_sp_scale(but_size, &menu->control.icon.sp);
    set_sp_scale(bg_size, &menu->bg);
    set_sp_scale((sfVector2f){6, 6}, &menu->moves);
    set_sp_scale((sfVector2f){6, 6}, &menu->input);
}

void set_button_position(menu_t *menu)
{
    set_sp_pos((sfVector2f){825, 600}, &menu->start.icon.sp);
    set_sp_pos((sfVector2f){825, 800}, &menu->setting.icon.sp);
    set_sp_pos((sfVector2f){825, 400}, &menu->back.icon.sp);
    set_sp_pos((sfVector2f){825, 600}, &menu->control.icon.sp);
    set_sp_pos((sfVector2f){1100, 600}, &menu->moves);
    set_sp_pos((sfVector2f){500, 600}, &menu->input);
}

menu_t create_menu(void)
{
    menu_t res = {0};

    res.playable = 0;
    res.bg = create_sprite(M_BG);
    res.start = create_button(START);
    res.setting = create_button(SET);
    res.back = create_button(BACK);
    res.control = create_button(CONT);
    res.moves = create_sprite(S_MV);
    res.input = create_sprite(S_IN);
    res.title = create_sprite("assets/title.png");
    set_menu_ani(&res);
    set_menu_scale((sfVector2f){2, 2}, (sfVector2f){3.55, 2.85}, &res);
    set_button_position(&res);
    sfSprite_setScale(res.title.sp, (sfVector2f){0.7, 0.7});
    sfSprite_setPosition(res.title.sp, (sfVector2f){520, 50});
    res.mus = sfMusic_createFromFile(M_MUS);
    return res;
}

void destroy_menu(menu_t menu)
{
    destroy_sprite(menu.bg);
    destroy_button(menu.start);
    destroy_button(menu.setting);
    destroy_button(menu.control);
    destroy_button(menu.back);
    destroy_sprite(menu.title);
    sfMusic_destroy(menu.mus);
}

void draw_menu(sfRenderWindow *win, menu_t menu)
{
    draw_sprite(win, menu.bg);
    draw_sprite(win, menu.start.icon.sp);
    draw_sprite(win, menu.setting.icon.sp);
    draw_sprite(win, menu.title);
}
