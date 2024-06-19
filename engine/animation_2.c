/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** ihave1frien
*/

#include "../include/rpg.h"

void set_ani_frames(int *new, anime_t *ani)
{
    can_free(ani->frames);
    ani->frames = my_intdup(new);
}

int anime_len(anime_t *src)
{
    int i = 0;

    for (; src && src[i].name; i++);
    return i;
}

anime_t *ani_append(anime_t *src, char *add, int *frames)
{
    anime_t *res = NULL;
    int i = 0;

    res = malloc(sizeof(anime_t) * (anime_len(src) + 2));
    if (!res)
        return NULL;
    for (; src && src[i].name; i++)
        res[i] = create_anime(src[i].name, src[i].frames);
    res[i] = create_anime(add, frames);
    res[i + 1] = (anime_t) {NULL, NULL, 0, false};
    can_free(src);
    return res;
}

anime_t find_anim(char *name, sprite_sheet_t s)
{
    int pos = locate_animation(name, &s);

    if (pos == -1)
        return (anime_t){0};
    return s.anime[pos];
}
