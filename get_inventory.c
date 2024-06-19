/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** get_inventory
*/

#include "rpg.h"

void monster_inventories(base_t *b)
{
    inv_t *s_inv = &b->scribs.inv;
    inv_t *i_inv = &b->ibis.inv;
    inv_t *b_inv = &b->baboon.inv;

    my_strcpy(s_inv->bandages.name, "bandages");
    my_strcpy(s_inv->bandages.description, "heals 3 health\npoints");
    my_strcpy(i_inv->s_ring.name, "defense earrings");
    my_strcpy(i_inv->s_ring.description, "reduces foe's\ndamage by\nhalf");
    my_strcpy(b_inv->d_ring.name, "attack earrings");
    my_strcpy(b_inv->d_ring.description, "doubles your\ndamage");
    b->scribs.inv.bandages.quantity = 1;
    b->ibis.inv.s_ring.quantity = 1;
    b->baboon.inv.d_ring.quantity = 1;
}

void get_inventory(base_t *b)
{
    inv_t *p_inv = &b->player.inv;

    my_strcpy(p_inv->bandages.name, "bandages");
    my_strcpy(p_inv->bandages.description, "heals 3 health points");
    my_strcpy(p_inv->s_ring.name, "defense earrings");
    my_strcpy(p_inv->s_ring.description, "reduces foe's damage by half");
    my_strcpy(p_inv->d_ring.name, "attack earrings");
    my_strcpy(p_inv->d_ring.description, "doubles your damage");
    monster_inventories(b);
}
