/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** link
*/

#include "rpg.h"

void link_game(base_t *b)
{
    if (sfMusic_getStatus(b->cu_mus) == sfPlaying)
        sfMusic_stop(b->cu_mus);
    b->scene.over = true;
    save_recup(b);
    overworld(b);
}
