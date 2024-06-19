/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** menu_pause_3
*/

#include "rpg.h"

void check_inv_collis(base_t *b, ingame_t *menu)
{
    menu->buttons.bdg.state = change_rec_state_1(menu->buttons.bdg.square,
    b, menu->buttons.bdg.state);
    menu->buttons.dring.state = change_rec_state_2(menu->buttons.dring.square,
    b, menu->buttons.dring.state);
    menu->buttons.sring.state = change_rec_state_3(menu->buttons.sring.square,
    b, menu->buttons.sring.state);
    equip_defring(&b->player, &menu->buttons.dring);
    equip_attring(&b->player, &menu->buttons.sring);
    return;
}

void copy_string(ingame_t *menu, enti_t player)
{
    my_strcpy(menu->def, "bandage : ");
    my_strcat(my_strnb_cpy(player.inv.bandages.quantity, menu->def),
    "\n\n\n\n");
    if (player.inv.d_ring.quantity) {
    my_strcat(menu->def, player.inv.d_ring.name);
    my_strcat(menu->def, " : ");
    my_strcat(my_strnb_cpy(player.inv.d_ring.quantity, menu->def),
    "\n\n\n");
    menu->buttons.dring.visible = true;
    }
    if (player.inv.s_ring.quantity) {
        my_strcat(menu->def, player.inv.s_ring.name);
        my_strcat(menu->def, " : ");
        my_strcat(my_strnb_cpy(player.inv.s_ring.quantity, menu->def), "");
        menu->buttons.sring.visible = true;
    }
}

void effect_of_inv(base_t *b, ingame_t *menu)
{
    copy_string(menu, b->player);
    sfText_setString(menu->txt, menu->def);
    menu->st.visible = true;
    menu->buttons.visible = true;
    my_memset(menu->def, 60, 0);
    sfText_setCharacterSize(menu->txt, 23);
    sfText_setPosition(menu->txt, (sfVector2f){420, 720});
    check_inv_collis(b, menu);
    set_sp_scale((sfVector2f){4, 5}, &menu->st);
    set_sp_pos((sfVector2f){400, 700}, &menu->st);
}

void apply_inv(base_t *b, ingame_t *m)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(b->win);
    sfFloatRect rect = get_sp_bounds(m->inv.sp);
    sfFloatRect rec = get_sp_bounds(m->st);

    if (!sfFloatRect_contains(&rect, mouse.x - 150, mouse.y + 260) &&
        !sfFloatRect_contains(&rec, mouse.x - 150, mouse.y + 260)) {
        m->state_inv = 0;
        play_anime("no touch", &m->inv);
        m->buttons.visible = false;
        return;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && m->state_inv != 2) {
        m->state_inv = 2;
        play_anime("clicked", &m->inv);
    } else if (m->state_inv != 2) {
        m->state_inv = 1;
        play_anime("over", &m->inv);
    }
    if (m->state_inv == 2)
        effect_of_inv(b, m);
}
