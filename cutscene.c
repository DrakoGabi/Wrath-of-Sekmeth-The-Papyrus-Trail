/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** cutscene
*/

#include "rpg.h"

int display_text(base_t *b, int i, int j)
{
    float t = sfTime_asSeconds(sfClock_getElapsedTime(b->player.cl));

    if (t <= 0.05)
        return j;
    sfClock_restart(b->player.cl);
    if (cin[i] && j + 1 <= my_strlen(cin[i]))
        my_strncpy(b->scene.src, cin[i], j + 1);
    sfText_setString(b->scene.aff, b->scene.src);
    return j + 1;
}

void draw_scene(base_t *b)
{
    draw_sprite(b->win, b->scene.bg);
    draw_sprite(b->win, b->scene.box);
    draw_sprite(b->win, b->press);
    draw_sprite(b->win, b->scene.p.sp);
    draw_sprite(b->win, b->scene.t.sp);
    draw_sprite(b->win, b->press);
    sfRenderWindow_drawText(b->win, b->scene.aff, NULL);
}

void cutscene_anim(cutscene_t *s, int i)
{
    char *p[] = {"c", "c", "c", "c", "c", "g", "g", "c", "c", "g", "g", "g",
                NULL};
    char *t[] = {"g", "g", "g", "g", "g", "c", "c", "g", "g", "g", "c", "c",
                NULL};
    int ps[] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0};
    int ts[] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1};

    play_anime(p[i], &s->p);
    play_anime(t[i], &s->t);
    s->p.sp.visible = ps[i];
    s->t.sp.visible = ts[i];
}

int reset_src(cutscene_t *s, int i)
{
    my_memset(s->src, 73, 0);
    sfText_setString(s->aff, s->src);
    return i + 1;
}

void cutscene(base_t *b)
{
    int i = 0;
    int j = 1;

    sfMusic_play(b->cu_mus);
    sfText_setString(b->scene.aff, b->scene.src);
    for (; sfRenderWindow_isOpen(b->win) && cin[i] && !b->scene.over;) {
        handle_event(b);
        sfRenderWindow_clear(b->win, sfBlack);
        j = display_text(b, i, j);
        cutscene_anim(&b->scene, i);
        if (just_pressed(b, sfKeyEnter)) {
            i = reset_src(&b->scene, i);
            j = 1;
        }
        draw_scene(b);
        sfRenderWindow_display(b->win);
    }
    link_game(b);
}
