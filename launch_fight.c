/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** launch_fight
*/

#include "rpg.h"

void are_you_fighting(base_t *base)
{
    int proba = 0;

    srand(time(NULL));
    proba = rand() % 10;
    if (proba == 9) {
        activate_fight(base, &base->scribs, OUSTIDE_BG, base->en_mus);
        set_level(base->player.stats.lvl, &base->scribs.stats, 1);
        base->scribs.alive = true;
    }
    sfView_setCenter(base->pov, get_sp_pos(base->player.map.sp));
    sfView_setSize(base->pov, (sfVector2f){(30 * 16), (20 * 16)});
    sfRenderWindow_setView(base->win, base->pov);
}
