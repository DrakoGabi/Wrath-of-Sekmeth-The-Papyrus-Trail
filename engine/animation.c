/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** animation
*/

#include "../include/rpg.h"

anime_t create_anime(char *name, int *frames)
{
    anime_t res = {0};

    res.name = my_strdup(name);
    res.frames = my_intdup(frames);
    res.loop = true;
    res.nb_frames = my_intlen(frames);
    return res;
}

void destroy_anime(anime_t ani)
{
    can_free(ani.name);
    can_free(ani.frames);
}

int first_anime(anime_t ani)
{
    if (!ani.nb_frames)
        return -1;
    return ani.frames[0];
}

int last_anime(anime_t ani)
{
    if (!ani.nb_frames)
        return -1;
    return ani.frames[ani.nb_frames - 1];
}

void set_ani_name(char *new, anime_t *ani)
{
    can_free(ani->name);
    ani->name = my_strdup(new);
}
