/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** flip
*/

#include "rpg.h"

void flip(sfVector2f f, int r, sprite_sheet_t *s)
{
    set_sp_scale(f, &s->sp);
    if (r == 16)
        play_anime("front", s);
    else
        play_anime("side", s);
}

sfVector2f get_pos(int direction, sprite_t pl)
{
    sfVector2f p = get_sp_pos(pl);

    if (!direction)
        return (sfVector2f){p.x - 8, p.y - 15};
    if (direction == 1)
        return (sfVector2f){p.x - 8, p.y - 4};
    if (direction == 2)
        return (sfVector2f){p.x - 12, p.y - 10};
    return (sfVector2f){p.x - 2, p.y - 10};
}
