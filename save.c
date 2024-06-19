/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** save
*/

#include "rpg.h"
#include "my.h"

save_t save_set(base_t *base)
{
    save_t save = {0};

    save.s_ring = base->player.inv.s_ring.quantity;
    save.d_ring = base->player.inv.d_ring.quantity;
    save.equip = base->player.inv.equip;
    save.bandage = base->player.inv.bandages.quantity;
    save.player_lv = base->player.stats.lvl;
    save.baboon = base->baboon.alive;
    save.ibis = base->ibis.alive;
    save.exp = base->exp;
    return save;
}

void set_save(base_t *base, save_t *save)
{
    base->player.inv.s_ring.quantity = save->s_ring;
    base->player.inv.d_ring.quantity = save->d_ring;
    base->player.inv.equip = save->equip;
    base->player.inv.bandages.quantity = save->bandage;
    base->player.stats.lvl = save->player_lv;
    base->baboon.alive = save->baboon;
    base->ibis.alive = save->ibis;
    base->exp = save->exp;
    base->player.alive = true;
    set_level(base->player.stats.lvl, &base->player.stats, 0);
    if (!base->baboon.alive){
        base->npc[2].alive = false;
        base->npc[4].alive = false;
    }
    if (!base->ibis.alive) {
        base->npc[1].alive = false;
        base->npc[3].alive = false;
    }
}

void save(base_t *base)
{
    FILE *text = fopen(".config", "w");
    save_t save = save_set(base);

    if (!text)
        return;
    fwrite(&save, sizeof(save_t), 1, text);
    fclose(text);
}

void save_recup(base_t *base)
{
    FILE *text = fopen(".config", "r");
    save_t save = {0};

    if (!text)
        return;
    fread(&save, sizeof(base_t), 1, text);
    write(1, &save, sizeof(save));
    set_save(base, &save);
    fclose(text);
}
