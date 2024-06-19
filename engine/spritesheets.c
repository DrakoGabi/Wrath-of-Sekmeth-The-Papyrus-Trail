/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** spritesheets
*/

#include "../include/rpg.h"

sprite_sheet_t create_sheets(char *path, int width)
{
    sprite_sheet_t res = {0};
    sfIntRect tmp = {0};

    res.sp = create_sprite(path);
    res.width = width;
    res.clock = sfClock_create();
    tmp = sfSprite_getTextureRect(res.sp.sp);
    tmp.width = width;
    sp_texture_rect(tmp, &res.sp);
    return res;
}

void destroy_sheets(sprite_sheet_t sht)
{
    for (int i = 0; sht.anime && sht.anime[i].name; i++)
        destroy_anime(sht.anime[i]);
    can_free(sht.anime);
    if (sht.clock)
        sfClock_destroy(sht.clock);
    can_free(sht.current_ani);
    destroy_sprite(sht.sp);
}

int locate_animation(char *ani, sprite_sheet_t *sht)
{
    int limit = anime_len(sht->anime);

    if (!sht->anime || !sht->anime->nb_frames) {
        sht->frame = 0;
        return -1;
    }
    for (int i = 0; i < limit; i++) {
        if (!my_strcmp(sht->anime[i].name, ani) &&
        !(!sht->anime[i].loop && sht->frame >= sht->anime[i].nb_frames))
            return i;
    }
    return -1;
}

void add_animation(char *new_ani, int *new_frames, sprite_sheet_t *sht)
{
    int exist = locate_animation(new_ani, sht);

    if (!new_ani)
        return;
    if (exist == -1 || !sht->anime)
        sht->anime = ani_append(sht->anime, new_ani, new_frames);
    else
        set_ani_frames(new_frames, &sht->anime[exist]);
}

void play_anime(char *ani, sprite_sheet_t *s)
{
    float timing = sfTime_asSeconds(sfClock_getElapsedTime(s->clock));
    sfIntRect rect = sfSprite_getTextureRect(s->sp.sp);
    int u = locate_animation(ani, s);

    if (u == -1)
        return;
    if (my_strcmp(ani, s->current_ani)) {
        s->frame = 0;
        s->current_ani = my_fstrdup(s->current_ani, ani);
    }
    if (timing >= 0.05) {
        if (s->frame >= my_intlen(s->anime[u].frames) && s->anime[u].loop) {
            s->frame = 0;
            rect.left = first_anime(s->anime[u]) * s->width;
        } else
            rect.left = s->width * s->anime[u].frames[s->frame];
        s->frame++;
        sp_texture_rect(rect, &s->sp);
        sfClock_restart(s->clock);
    }
}
