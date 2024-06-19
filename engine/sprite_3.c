/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** sprite_sequel
*/

#include "../include/rpg.h"

sfFloatRect get_sp_bounds(sprite_t sp)
{
    return sfSprite_getGlobalBounds(sp.sp);
}

bool is_clicked(sfRenderWindow *win, sprite_t sp)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win);
    sfFloatRect rekt = get_sp_bounds(sp);

    if (!sfMouse_isButtonPressed(sfMouseLeft))
        return false;
    if (sfFloatRect_contains(&rekt, mouse.x, mouse.y));
        return true;
    return false;
}

void set_sp_origin(sfVector2f ori, sprite_t *sp)
{
    sfSprite_setOrigin(sp->sp, ori);
}

void sp_texture_rect(sfIntRect rekt, sprite_t *sp)
{
    sfSprite_setTextureRect(sp->sp, rekt);
}
