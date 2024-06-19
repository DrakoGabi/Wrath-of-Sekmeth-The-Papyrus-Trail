/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** activate_boss
*/

#include "rpg.h"

bool window_fight_con(base_t *b)
{
    bool a = b->fstate.player->alive && b->fstate.enemy->alive;
    bool c = sfRenderWindow_isOpen(b->win);

    if (!my_strcmp(b->fstate.enemy->s.current_ani, "att"))
        return true;
    if (!my_strcmp(b->fstate.player->s.current_ani, "claw"))
        return true;
    if (!my_strcmp(b->fstate.player->s.current_ani, "breath"))
        return true;
    return (a && c);
}

bool is_playing(char *name, enti_t *ent)
{
    if (my_strcmp(ent->s.current_ani, name) != 0)
        return false;
    if (ent->s.frame != my_intlen(find_anim(name, ent->s).frames))
        return false;
    return true;
}

void animation_manager(fight_t *f)
{
    play_anime(f->enemy->s.current_ani, &f->enemy->s);
    if (is_playing("att", f->enemy))
        play_anime("idle", &f->enemy->s);
    play_anime(f->player->s.current_ani, &f->player->s);
    if (is_playing("claw", f->player) || is_playing("breath", f->player))
        play_anime("idle", &f->player->s);
}

void activate_bosses(base_t *b)
{
    if (!b->npc[1].alive && coll(b, 2) && b->ibis.alive) {
        activate_fight(b, &b->ibis, INSIDE_BG, b->ib_mus);
        b->npc[2].alive = false;
        b->npc[3].alive = false;
    }
    if (!b->npc[2].alive && coll(b, 3) && b->baboon.alive) {
        activate_fight(b, &b->baboon, INSIDE_BG, b->ba_mus);
        b->npc[4].alive = false;
    }
    if (!b->npc[3].alive && !b->npc[4].alive && coll(b, 4) && b->thot.alive)
        activate_fight(b, &b->thot, THOT_BG, b->th_mus);
}
