/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** menu_pause_2
*/

#include "rpg.h"

void handle_event_pause(base_t *base)
{
    while (sfRenderWindow_pollEvent(base->win, &base->evt)) {
        if (base->evt.type == sfEvtClosed ||
        just_pressed(base, sfKeyEscape))
            sfRenderWindow_close(base->win);
        apply_stats(base, &base->pause);
        apply_inv(base, &base->pause);
        apply_save(base, &base->pause);
    }
}

void set_pause_ani_2(ingame_t *res)
{
    int *framez = append_int(NULL, 0);

    add_animation("no touch", framez, &res->save);
    can_free(framez);
    framez = append_int(NULL, 1);
    add_animation("over", framez, &res->save);
    can_free(framez);
    framez = append_int(NULL, 2);
    add_animation("clicked", framez, &res->save);
    can_free(framez);
}

void set_pause_ani(ingame_t *res)
{
    int *framez = append_int(NULL, 0);

    add_animation("no touch", framez, &res->stats);
    can_free(framez);
    framez = append_int(NULL, 1);
    add_animation("over", framez, &res->stats);
    can_free(framez);
    framez = append_int(NULL, 2);
    add_animation("clicked", framez, &res->stats);
    can_free(framez);
    framez = append_int(NULL, 0);
    add_animation("no touch", framez, &res->inv);
    can_free(framez);
    framez = append_int(NULL, 1);
    add_animation("over", framez, &res->inv);
    can_free(framez);
    framez = append_int(NULL, 2);
    add_animation("clicked", framez, &res->inv);
    can_free(framez);
    set_pause_ani_2(res);
}

void effect_of_stats(base_t *b, ingame_t *menu)
{
    my_strcpy(menu->def, "lvl : ");
    my_strcat(my_strnb_cpy(b->player.stats.lvl, menu->def), "\n\nexp : ");
    my_strcat(my_strnb_cpy(b->exp, menu->def), "/100\n\nhp : ");
    my_strcat(my_strnb_cpy(b->player.stats.hp, menu->def), "\n\nattack : ");
    my_strcat(my_strnb_cpy(b->player.stats.atk, menu->def), "\n\nclock : ");
    my_strnb_cpy(b->player.stats.cl, menu->def);
    sfText_setString(menu->txt, menu->def);
    menu->st.visible = true;
    my_memset(menu->def, 60, 0);
    sfText_setCharacterSize(menu->txt, 23);
    sfText_setPosition(menu->txt, (sfVector2f){550, 720});
    set_sp_scale((sfVector2f){2, 5}, &menu->st);
    set_sp_pos((sfVector2f){540, 700}, &menu->st);
    return;
}

void apply_stats(base_t *b, ingame_t *m)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(b->win);
    sfFloatRect rect = get_sp_bounds(m->stats.sp);

    if (!sfFloatRect_contains(&rect, mouse.x - 150, mouse.y + 290)) {
        m->states_state = 0;
        play_anime("no touch", &m->stats);
        m->st.visible = false;
        return;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && m->states_state != 2) {
        m->states_state = 2;
        play_anime("clicked", &m->stats);
    } else if (m->states_state != 2) {
        m->states_state = 1;
        play_anime("over", &m->stats);
    }
    if (m->states_state == 2)
        effect_of_stats(b, m);
    else
        m->st.visible = false;
}
