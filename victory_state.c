/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** victory_state
*/

#include "rpg.h"

void add_inventory(base_t *b)
{
    inv_t *p = &b->fstate.player->inv;
    inv_t *e = &b->fstate.enemy->inv;

    p->bandages.quantity += e->bandages.quantity;
    p->d_ring.quantity += e->d_ring.quantity;
    p->s_ring.quantity += e->s_ring.quantity;
}

victory_t create_victory(sfFont *f)
{
    victory_t res = {0};

    res.bg = create_sprite(VICTORY);
    res.ex = set_text("a", f, sfBlack);
    res.it = set_text("b", f, sfBlack);
    res.st = set_text("c", f, sfBlack);
    sfText_setCharacterSize(res.ex, 50);
    sfText_setPosition(res.ex, (sfVector2f){355, 330});
    sfText_setCharacterSize(res.it, 50);
    sfText_setPosition(res.it, (sfVector2f){355, 550});
    sfText_setCharacterSize(res.st, 50);
    sfText_setPosition(res.st, (sfVector2f){1075, 330});
    return res;
}

item_t search_item(inv_t i)
{
    if (i.bandages.quantity)
        return i.bandages;
    if (i.d_ring.quantity)
        return i.d_ring;
    return i.s_ring;
}

void setup_vic(base_t *b)
{
    victory_t *v = &b->fstate.vic;
    stat_t *s = &b->fstate.player->stats;

    my_memset(v->e, 10, 0);
    my_memset(v->i, 48, 0);
    my_memset(v->s, 43, 0);
    my_strcpy(v->i, search_item(b->fstate.enemy->inv).name);
    my_strcat(v->i, "\n");
    my_strcat(v->i, search_item(b->fstate.enemy->inv).description);
    my_strcpy(v->e, "exp + ");
    my_strnb_cpy(b->fstate.enemy->stats.exp, v->e);
    my_strcpy(v->s, "\tlvl : ");
    my_strcat(my_strnb_cpy(s->lvl, v->s), "\nhp : ");
    my_strcat(my_strnb_cpy(s->hp, v->s), "\nattack : ");
    my_strcat(my_strnb_cpy(s->atk, v->s), "\nclock : ");
    my_strnb_cpy(s->cl, v->s);
    sfText_setString(v->ex, v->e);
    sfText_setString(v->it, v->i);
    sfText_setString(v->st, v->s);
}

void victory_loop(base_t *b)
{
    setup_vic(b);
    stop_combat_music(b);
    sfMusic_play(b->vi_mus);
    for (; sfRenderWindow_isOpen(b->win);) {
        handle_event(b);
        sfRenderWindow_clear(b->win, sfBlack);
        draw_sprite(b->win, b->fstate.vic.bg);
        sfRenderWindow_drawText(b->win, b->fstate.vic.ex, NULL);
        sfRenderWindow_drawText(b->win, b->fstate.vic.it, NULL);
        sfRenderWindow_drawText(b->win, b->fstate.vic.st, NULL);
        draw_sprite(b->win, b->press);
        sfRenderWindow_display(b->win);
        if (just_pressed(b, sfKeyEnter))
            break;
    }
}
