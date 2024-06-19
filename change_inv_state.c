/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** change_inv_state
*/

#include "rpg.h"

bool change_rec_state_1(sfRectangleShape *rec, base_t *b, bool sta)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(b->win);
    sfFloatRect r = sfRectangleShape_getGlobalBounds(rec);
    int hp = b->player.stats.hp;
    int max_hp = b->player.stats.maxhp;

    if (!sfFloatRect_contains(&r, m.x - 130, m.y + 270))
        return sta;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        sfRectangleShape_setFillColor(rec, sfGreen);
        sta = true;
        if (b->player.inv.bandages.quantity > 0) {
            b->player.inv.bandages.quantity -= 1;
            b->player.stats.hp = (hp +3 > max_hp) ? max_hp : (hp + 3);
        }
        return sta;
    }
    sfRectangleShape_setFillColor(rec, sfRed);
    sta = false;
    return sta;
}

bool change_rec_state_2(sfRectangleShape *rec, base_t *b, bool sta)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(b->win);
    sfFloatRect r = sfRectangleShape_getGlobalBounds(rec);

    if (!sfFloatRect_contains(&r, m.x - 140, m.y + 320))
        return sta;
    if (sfMouse_isButtonPressed(sfMouseLeft) && sta) {
        sfRectangleShape_setFillColor(rec, sfRed);
        sta = false;
    } else if (sfMouse_isButtonPressed(sfMouseLeft) && !sta) {
        sfRectangleShape_setFillColor(rec, sfGreen);
        sta = true;
    }
    return sta;
}

bool change_rec_state_3(sfRectangleShape *rec, base_t *b, bool sta)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(b->win);
    sfFloatRect r = sfRectangleShape_getGlobalBounds(rec);

    if (!sfFloatRect_contains(&r, m.x - 140, m.y + 300))
        return sta;
    if (sfMouse_isButtonPressed(sfMouseLeft) && sta) {
        sfRectangleShape_setFillColor(rec, sfRed);
        return false;
    } else if (sfMouse_isButtonPressed(sfMouseLeft) && !sta) {
        sfRectangleShape_setFillColor(rec, sfGreen);
        return true;
    }
    return sta;
}

void equip_defring(enti_t *player, square_button_t *s)
{
    if (player->inv.equip == ATT_RING) {
        sfRectangleShape_setFillColor(s->square, sfRed);
        return;
    }
    if (player->inv.d_ring.quantity > 0 && !s->state)
            player->inv.equip = NOTHING;
    else if (player->inv.d_ring.quantity > 0 && s->state
            && player->inv.equip == NOTHING)
            player->inv.equip = DEF_RING;
}

void equip_attring(enti_t *player, square_button_t *s)
{
    if (player->inv.equip == DEF_RING) {
        sfRectangleShape_setFillColor(s->square, sfRed);
        return;
    }
    if (player->inv.s_ring.quantity > 0 && !s->state)
            player->inv.equip = NOTHING;
    else if (player->inv.s_ring.quantity > 0 && s->state
            && player->inv.equip == NOTHING)
            player->inv.equip = ATT_RING;
}
