/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** memory_cutscene
*/

#include "rpg.h"

void set_scene(cutscene_t *s)
{
    set_sp_scale((sfVector2f){2, 2.4}, &s->bg);
    set_sp_scale((sfVector2f){18, 2}, &s->box);
    set_sp_pos((sfVector2f){250, 900}, &s->box);
    set_sp_scale((sfVector2f){3, 3}, &s->t.sp);
    set_sp_pos((sfVector2f){450, 550}, &s->t.sp);
    set_sp_scale((sfVector2f){3, 3}, &s->p.sp);
    set_sp_pos((sfVector2f){1150, 550}, &s->p.sp);
    sfText_setPosition(s->aff, (sfVector2f){320, 935});
}

cutscene_t create_cutcsecne(sfFont *f)
{
    cutscene_t res = {0};
    int *a = frame_getter(0, 1);
    int *b = frame_getter(1, 2);

    res.aff = set_text("", f, sfBlack);
    res.bg = create_sprite(INSIDE_BG);
    res.box = create_sprite(ZONE);
    res.p = create_sheets(P_POR, 119);
    res.t = create_sheets(T_POR, 119);
    set_scene(&res);
    add_animation("c", a, &res.p);
    add_animation("g", b, &res.p);
    add_animation("c", a, &res.t);
    add_animation("g", b, &res.t);
    can_free(a);
    can_free(b);
    return res;
}

void destroy_cutscene(cutscene_t s)
{
    sfText_destroy(s.aff);
    destroy_sheets(s.p);
    destroy_sheets(s.t);
    destroy_sprite(s.bg);
    destroy_sprite(s.box);
}
