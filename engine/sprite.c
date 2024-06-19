/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** sprite
*/

#include "../include/rpg.h"
#include <stdio.h>

sprite_t create_sprite(char *pathname)
{
    sprite_t res = {0};

    res.sp = sfSprite_create();
    if (pathname)
        res.tex = sfTexture_createFromFile(pathname, NULL);
    else
        res.tex = sfTexture_create(1920, 1080);
    sfSprite_setTexture(res.sp, res.tex, sfFalse);
    res.visible = true;
    return res;
}

void destroy_sprite(sprite_t sp)
{
    if (sp.sp)
        sfSprite_destroy(sp.sp);
    if (sp.tex)
        sfTexture_destroy(sp.tex);
}

void draw_sprite(sfRenderWindow *win, sprite_t sp)
{
    if (sp.visible && sp.sp)
        sfRenderWindow_drawSprite(win, sp.sp, NULL);
}

void set_sp_pos(sfVector2f pos, sprite_t *sp)
{
    if (!sp->sp)
        return;
    sfSprite_setPosition(sp->sp, pos);
}

sfVector2f get_sp_pos(sprite_t sp)
{
    return sfSprite_getPosition(sp.sp);
}
