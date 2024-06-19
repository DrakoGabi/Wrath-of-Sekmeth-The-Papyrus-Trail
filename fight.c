/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** fight
*/

#include "rpg.h"

int is_activ(fight_t *f)
{
    int i = 0;

    for (; i < 2; i++)
        if (f->spell[i].bg.visible && f->spell[i].activ)
            return i;
    return 0;
}

void color_button(base_t *b)
{
    for (int i = 0; i < 2; i++) {
        if (b->fstate.spell[i].activ && b->fstate.spell[i].bg.visible)
            sfText_setFillColor(b->fstate.spell[i].txt, sfGreen);
        if (!b->fstate.spell[i].activ && b->fstate.spell[i].bg.visible)
            sfText_setFillColor(b->fstate.spell[i].txt, sfRed);
    }
}

bool player_choice(base_t *b)
{
    int act = is_activ(&b->fstate);

    if (just_pressed(b, sfKeyLeft) && act) {
        act = 0;
        b->fstate.spell[0].activ = true;
        b->fstate.spell[1].activ = false;
    }
    if (just_pressed(b, sfKeyRight) && b->fstate.spell[1].bg.visible) {
        act = 1;
        b->fstate.spell[1].activ = true;
        b->fstate.spell[0].activ = false;
    }
    color_button(b);
    b->fstate.player->att = b->fstate.spell[act].len;
    if (just_pressed(b, sfKeyEnter) && !b->fstate.start)
        return true;
    return false;
}

void redirect_fight(base_t *b)
{
    fight_t *f = &b->fstate;

    animation_manager(f);
    if (play_fight(b) || !f->start)
        reset_fight(b);
    if (player_choice(b)) {
        set_answer(f->ent.ref, f->player->att);
        sfText_setString(f->ent.r, f->ent.ref);
        f->start = true;
        f->turn = true;
    }
}

void reset_fight(base_t *b)
{
    fight_t *f = &b->fstate;

    sfText_setString(f->ent.ent, "");
    sfText_setString(f->ent.r, "");
    my_memset(f->ent.enter, 9, 0);
    my_memset(f->ent.ref, 9, 0);
    sfClock_restart(b->player.cl);
}
