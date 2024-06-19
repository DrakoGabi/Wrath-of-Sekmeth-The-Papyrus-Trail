/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** npc
*/

#include "rpg.h"

npc_t create_npc(char *m, sfFont *f, sfVector2f p)
{
    npc_t res = {0};

    res.self = create_sprite(NPC);
    res.alive = true;
    res.box = create_sprite(BOX);
    res.txt = sfText_create();
    sfText_setString(res.txt, m);
    sfText_setFont(res.txt, f);
    set_sp_pos(p, &res.self);
    set_sp_pos((sfVector2f){p.x - 40, p.y - 70}, &res.box);
    sfText_setPosition(res.txt, (sfVector2f){p.x - 35, p.y - 65});
    res.box.visible = false;
    set_sp_scale((sfVector2f){0.5, 0.5}, &res.self);
    set_sp_scale((sfVector2f){1.2, 1.2}, &res.box);
    sfText_setFillColor(res.txt, sfBlack);
    sfText_setCharacterSize(res.txt, 14);
    return res;
}

void destroy_npc(npc_t n)
{
    destroy_sprite(n.self);
    destroy_sprite(n.box);
    sfText_destroy(n.txt);
}

void get_npc(base_t *b)
{
    b->npc[0] = create_npc("The great\nThot is waiting\nup north.",
    b->font, (sfVector2f){631, 1450});
    b->npc[1] = create_npc("You are too weak\nfor my master.\nGet good.",
    b->font, (sfVector2f){119, 730});
    b->npc[2] = create_npc("Conquer the sky\nbefore fighting\nthe smart one.",
    b->font, (sfVector2f){1495, 730});
    b->npc[3] = create_npc("I am error!\nThe bird must be\ndefeated.",
    b->font, (sfVector2f){787, 90});
    b->npc[4] = create_npc("My name is bug!\nThe monkey must\nbe defeated.",
    b->font, (sfVector2f){795, 90});
}

void draw_npc(sfRenderWindow *win, npc_t npc)
{
    if (!npc.alive)
        return;
    draw_sprite(win, npc.self);
    if (npc.box.visible) {
        draw_sprite(win, npc.box);
        sfRenderWindow_drawText(win, npc.txt, NULL);
    }
}

void collide_npc(base_t *b, int i)
{
    npc_t *n = b->npc;

    if (!n[i].alive)
        return;
    if (sp_collide(b->player.map.sp, n[i].self) &&
        just_pressed(b, sfKeySpace)) {
        if (!n[i].box.visible) {
            n[i].box.visible = true;
            return;
        }
        if (n[i].box.visible)
            n[i].box.visible = false;
    }
}
