/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** check_entry
*/

#include "rpg.h"

bool coll_up(base_t *b, int i)
{
    sfVector2f pos = get_sp_pos(b->player.map.sp);
    int x = pos.x / 16;
    int y = (pos.y -3) / 16;
    int x2 = (pos.x + b->player.map.width) / 16;
    int in = (int)(x + y * (int)(b->map.height));
    int in2 = (int)(x2 + y * (int)(b->map.height));

    return (b->map.layers.indexes[in] == i || b->map.layers.indexes[in2] == i);
}

bool coll_down(base_t *b, int i)
{
    sfVector2f pos = get_sp_pos(b->player.map.sp);
    sfIntRect size = sfSprite_getTextureRect(b->player.map.sp.sp);
    int x = pos.x / 16;
    int y = (pos.y + size.height + 3) / 16;
    int x2 = (pos.x + b->player.map.width) / 16;
    int in = (int)(x + y * (int)(b->map.height));
    int in2 = (int)(x2 + y * (int)(b->map.height));

    return (b->map.layers.indexes[in] == i || b->map.layers.indexes[in2] == i);
}

bool coll_left(base_t *b, int i)
{
    sfVector2f pos = get_sp_pos(b->player.map.sp);
    sfIntRect size = sfSprite_getTextureRect(b->player.map.sp.sp);
    int x = (pos.x -3) / 16;
    int y = pos.y / 16;
    int y2 = (pos.y + size.height) / 16;
    int in2 = (int)(x + y2 * (int)(b->map.width));
    int in = (int)(x + y * (int)(b->map.width));

    return (b->map.layers.indexes[in] == i || b->map.layers.indexes[in2] == i);
}

bool coll_right(base_t *b, int i)
{
    sfVector2f pos = get_sp_pos(b->player.map.sp);
    sfIntRect size = sfSprite_getTextureRect(b->player.map.sp.sp);
    int x = (pos.x + b->player.map.width + 3) / 16;
    int y = pos.y / 16;
    int in = (int)(x + y * (int)(b->map.width));
    int y2 = (pos.y + size.height) / 16;
    int in2 = (int)(x + y2 * (int)(b->map.width));

    return (b->map.layers.indexes[in] == i || b->map.layers.indexes[in2] == i);
}

bool coll(base_t *b, int i)
{
    return (coll_left(b, i) || coll_right(b, i) ||
    coll_down(b, i) || coll_up(b, i));
}
