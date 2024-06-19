/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** main
*/

#include "rpg.h"

base_t create_base(char *title)
{
    base_t res = {0};

    res.win = sfRenderWindow_create((sfVideoMode) {1920, 1080, 32},
    title, sfClose | sfResize, NULL);
    res.fight_font = sfFont_createFromFile(FIGHT_FONT);
    res.font = sfFont_createFromFile(FONT);
    res.menu = create_menu();
    res.fstate = create_fight(res.fight_font);
    res.map = create_map(100, 100, 16, OVERWORLD);
    res.pov = create_view();
    res.input = create_sprite(INTERACT);
    res.pause = create_pause(res.font);
    res.scene = create_cutcsecne(res.font);
    res.press = create_sprite(PRESS);
    get_all_music(&res);
    get_entity(&res);
    get_npc(&res);
    get_inventory(&res);
    return res;
}

void destroy_base(base_t base)
{
    sfRenderWindow_destroy(base.win);
    if (base.font)
        sfFont_destroy(base.font);
    destroy_all_music(&base);
    destroy_entity(base.scribs);
    destroy_entity(base.player);
    destroy_entity(base.ibis);
    destroy_entity(base.baboon);
    destroy_entity(base.thot);
    destroy_menu(base.menu);
    destroy_fight(base.fstate);
    destroy_view(base.pov);
    destroy_sprite(base.input);
    destroy_all_npc(&base);
    destroy_pause(base.pause);
    destroy_cutscene(base.scene);
}

void menu_loop(base_t *base)
{
    sfMusic_play(base->menu.mus);
    replace_sp_tex(M_BG, &base->menu.bg);
    sfSprite_setScale(base->menu.bg.sp, (sfVector2f){3.55, 2.85});
    for (; sfRenderWindow_isOpen(base->win);) {
        handle_event(base);
        sfRenderWindow_clear(base->win, sfBlack);
        draw_menu(base->win, base->menu);
        anime_button(&base->menu.start);
        anime_button(&base->menu.setting);
        sfRenderWindow_display(base->win);
        if (base->menu.playable == 2)
            setting_loop(base);
        if (base->menu.playable == 1)
            break;
    }
    sfView_setCenter(base->pov, (sfVector2f){620, 1500});
    sfView_setSize(base->pov, (sfVector2f){(30 * 16), (20 * 16)});
    sfMusic_stop(base->menu.mus);
    if (sfRenderWindow_isOpen(base->win))
        overworld(base);
}

int main(void)
{
    base_t base = create_base("Wrath of Sekhmet: The Papyrus Trail");

    set_sp_pos((sfVector2f){1500, 960}, &base.press);
    set_sp_scale((sfVector2f){3, 3}, &base.press);
    base.fstate.player = &base.player;
    sfRenderWindow_setFramerateLimit(base.win, 30);
    menu_loop(&base);
    destroy_base(base);
    return 0;
}
