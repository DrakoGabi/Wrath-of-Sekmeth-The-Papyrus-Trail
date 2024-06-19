/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** npc_2
*/

#include "rpg.h"

void draw_all_npc(base_t *b)
{
    for (int i = 0; i < 5; i++)
        draw_npc(b->win, b->npc[i]);
}

void collide_all_npc(base_t *b)
{
    for (int i = 0; i < 5; i++)
        collide_npc(b, i);
}

void collide_npc_input(base_t *b)
{
    int i = 0;
    npc_t *n = b->npc;
    sfVector2f pos = {0};

    for (i = 0; i < 5; i++) {
        if (sp_collide(b->player.map.sp, n[i].self) && n[i].alive)
            break;
    }
    if (i < 5) {
        pos = get_sp_pos(n[i].self);
        set_sp_pos((sfVector2f){pos.x - 5, pos.y + 50}, &b->input);
        b->input.visible = true;
    } else if (i == 5)
        b->input.visible = false;
}

void destroy_all_npc(base_t *b)
{
    for (int i = 0; i < 5; i++)
        destroy_npc(b->npc[i]);
}
