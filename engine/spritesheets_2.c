/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** spritesheets_2
*/

#include "../include/rpg.h"

void set_loop(sprite_sheet_t *sht, char *ani, bool pool)
{
    int loc = locate_animation(sht->anime->name, sht);

    if (loc == -1)
        return;
    sht->anime[loc].loop = pool;
}
