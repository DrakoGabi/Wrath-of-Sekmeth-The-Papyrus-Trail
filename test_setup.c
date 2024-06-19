/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** test_setup
*/

#include "rpg.h"

void set_level(int lvl, stat_t *stats, int indstat)
{
    stats->lvl = lvl;
    stats->maxhp = bstats[indstat].maxhp + (int)(5 * ((lvl - 1) / 4));
    stats->hp = stats->maxhp;
    stats->atk = bstats[indstat].atk + (int)(lvl / 2);
    stats->cl = bstats[indstat].cl + (int)((lvl - 3) / 4 + 1);
    stats->exp = bstats[indstat].exp;
}

int *frame_getter(int start, int size)
{
    int *res = malloc(sizeof(int) * (size - start + 1));
    int i = 0;

    if (!res)
        return res;
    for (; i < (size - start); i++)
        res[i] = start + i;
    res[i] = -1;
    return res;
}

enti_t create_entity(char *name, int indstat, int lvl)
{
    enti_t res = {0};

    res.alive = true;
    res.cl = sfClock_create();
    res.name = my_strdup(name);
    set_level(lvl, &res.stats, indstat);
    res.att = 2;
    if (indstat == 0)
        get_player(&res);
    if (indstat == 1)
        get_enemy(&res);
    if (indstat == 2)
        get_baboon(&res);
    if (indstat == 3)
        get_ibis(&res);
    if (indstat == 4)
        get_thot(&res);
    return res;
}

void get_entity(base_t *base)
{
    int *anim = frame_getter(0, 7);

    base->player = create_entity("player", 0, 5);
    base->scribs = create_entity("scrib", 1, 1);
    base->baboon = create_entity("baboon", 2, 10);
    base->ibis = create_entity("ibis", 3, 5);
    base->thot = create_entity("thot", 4, 15);
    base->player.map = create_sheets(P_MAP, 40);
    add_animation("side", my_intdup(anim), &base->player.map);
    can_free(anim);
    anim = frame_getter(7, 13);
    add_animation("front", my_intdup(anim), &base->player.map);
    can_free(anim);
    set_sp_origin((sfVector2f){15, 16}, &base->player.map.sp);
}

void destroy_entity(enti_t ent)
{
    can_free(ent.name);
    sfClock_destroy(ent.cl);
    destroy_sheets(ent.s);
}
