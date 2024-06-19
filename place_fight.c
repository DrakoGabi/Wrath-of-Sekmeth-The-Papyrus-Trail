/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** place_fight
*/

#include "rpg.h"

int damage(enti_t *ent, base_t *b)
{
    int res = ent->stats.atk;

    play_anime("att", &b->fstate.enemy->s);
    for (int i = 0; i < ent->att; i++)
        res += (rand() % 2) ? 1 : 0;
    res = (ent->inv.equip == ATT_RING) ? res * 2 : res;
    return res;
}

void takes_hit(base_t *b, enti_t *ent, int hit)
{
    hit = (ent->inv.equip == DEF_RING) ? hit / 2 : hit;
    ent->stats.hp -= hit;
    if (ent->stats.hp <= 0) {
        ent->stats.hp = 0;
        ent->alive = false;
    }
    set_hp(&b->fstate);
}

bool enemy_phase(base_t *b)
{
    fight_t *f = &b->fstate;

    if (!my_strcmp(f->player->s.current_ani, "claw")
        || !my_strcmp(f->player->s.current_ani, "breath")
        || !f->enemy->alive)
        return true;
    play_anime("att", &f->enemy->s);
    sfText_setString(b->fstate.ent.r, b->fstate.ent.ref);
    b->fstate.start = false;
    b->fstate.turn = true;
    takes_hit(b, b->fstate.player, damage(b->fstate.enemy, b));
    return true;
}

bool play_fight(base_t *b)
{
    bool wait = player_wait(b, b->fstate.player->att);

    if (!b->fstate.start)
        return false;
    if (!wait && b->fstate.turn) {
        takes_hit(b, b->fstate.enemy, player_attack(b));
        b->fstate.turn = false;
    }
    if (!b->fstate.turn)
        return enemy_phase(b);
    return false;
}

int fight(base_t *b)
{
    while (window_fight_con(b)) {
        handle_event(b);
        sfRenderWindow_clear(b->win, sfBlack);
        redirect_fight(b);
        draw_fstate(&b->fstate, b->win);
        sfRenderWindow_display(b->win);
    }
    if (b->fstate.player->alive) {
        b->exp += b->fstate.enemy->stats.exp;
        add_inventory(b);
        level_up(b);
        victory_loop(b);
    } else
        die(b);
    return 0;
}
