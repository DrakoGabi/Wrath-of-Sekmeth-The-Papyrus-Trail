/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** entities
*/

#include "rpg.h"

void get_enemy(enti_t *e)
{
    int *anim = NULL;

    e->s = create_sheets(SCRIB, 266);
    anim = frame_getter(0, 6);
    add_animation("idle", my_intdup(anim), &e->s);
    can_free(anim);
    anim = frame_getter(6, 16);
    add_animation("att", my_intdup(anim), &e->s);
    can_free(anim);
    set_sp_scale((sfVector2f){3, 3}, &e->s.sp);
    set_sp_pos((sfVector2f){200, 450}, &e->s.sp);
}

void get_player(enti_t *e)
{
    int *anim = NULL;

    e->s = create_sheets(PLAYER, 356);
    anim = frame_getter(0, 11);
    add_animation("idle", my_intdup(anim), &e->s);
    can_free(anim);
    anim = frame_getter(11, 19);
    add_animation("claw", my_intdup(anim), &e->s);
    can_free(anim);
    anim = frame_getter(19, 32);
    add_animation("breath", my_intdup(anim), &e->s);
    set_sp_scale((sfVector2f){2.5, 2.5}, &e->s.sp);
    set_sp_pos((sfVector2f){860, 310}, &e->s.sp);
    can_free(anim);
}

void get_baboon(enti_t *e)
{
    int *anim = NULL;

    e->s = create_sheets(BABOON, 64);
    anim = frame_getter(4, 6);
    add_animation("idle", my_intdup(anim), &e->s);
    can_free(anim);
    anim = frame_getter(0, 4);
    add_animation("att", my_intdup(anim), &e->s);
    can_free(anim);
    set_sp_scale((sfVector2f){5, 5}, &e->s.sp);
    set_sp_pos((sfVector2f){450, 450}, &e->s.sp);
}

void get_ibis(enti_t *e)
{
    int *anim = NULL;

    e->s = create_sheets(IBIS, 182);
    anim = frame_getter(0, 5);
    add_animation("idle", my_intdup(anim), &e->s);
    can_free(anim);
    anim = frame_getter(5, 34);
    add_animation("att", my_intdup(anim), &e->s);
    set_sp_scale((sfVector2f){2.5, 2.5}, &e->s.sp);
    set_sp_pos((sfVector2f){450, 310}, &e->s.sp);
    can_free(anim);
}

void get_thot(enti_t *e)
{
    int *anim = NULL;

    e->s = create_sheets(THOT, 302);
    anim = frame_getter(10, 17);
    add_animation("idle", my_intdup(anim), &e->s);
    can_free(anim);
    anim = frame_getter(0, 10);
    add_animation("att", my_intdup(anim), &e->s);
    set_sp_scale((sfVector2f){2.5, 2.5}, &e->s.sp);
    set_sp_pos((sfVector2f){450, 310}, &e->s.sp);
    can_free(anim);
}
