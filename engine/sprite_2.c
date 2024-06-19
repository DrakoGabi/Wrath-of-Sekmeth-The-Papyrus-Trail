/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** sprite_dlc
*/

#include "../include/rpg.h"

void sp_move(sprite_t sp, float x, float y)
{
    sfSprite_move(sp.sp, (sfVector2f){x, y});
}

void set_sp_scale(sfVector2f scale, sprite_t *sp)
{
    sfSprite_setScale(sp->sp, scale);
}

void replace_sp_tex(char *path, sprite_t *sp)
{
    if (sp->tex)
        sfTexture_destroy(sp->tex);
    sp->tex = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(sp->sp, sp->tex, sfFalse);
}

bool sp_collide(sprite_t sp, sprite_t ot)
{
    sfFloatRect coli = sfSprite_getGlobalBounds(sp.sp);
    sfFloatRect lico = sfSprite_getGlobalBounds(ot.sp);

    if (sfFloatRect_intersects(&coli, &lico, NULL))
        return true;
    return false;
}
