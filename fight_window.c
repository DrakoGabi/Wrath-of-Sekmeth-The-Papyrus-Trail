/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** fight_window
*/

#include "rpg.h"

void destroy_fight(fight_t f)
{
    destroy_sprite(f.bg);
    destroy_sprite(f.spell[0].bg);
    sfText_destroy(f.spell[0].txt);
    destroy_sprite(f.spell[1].bg);
    sfText_destroy(f.spell[1].txt);
    sfText_destroy(f.ent.ent);
    sfText_destroy(f.ent.r);
    sfText_destroy(f.hp_dis.ent);
    sfText_destroy(f.hp_dis.r);
    sfText_destroy(f.vic.ex);
    sfText_destroy(f.vic.it);
    sfText_destroy(f.vic.st);
    destroy_sprite(f.vic.bg);
}

void add_nb(int nbr, char *dest)
{
    int power = 10;
    int tmp = 0;

    if (nbr < power)
        return add_char(dest, nbr + '0', 9);
    for (; nbr / power > 9;)
        power *= 10;
    for (; power >= 1;) {
        tmp = nbr / power;
        add_char(dest, tmp + '0', 9);
        nbr %= power;
        power /= 10;
    }
}

void activate_fight(base_t *base, enti_t *en, char *bg_path, sfMusic *mus)
{
    sfView_setCenter(base->pov, (sfVector2f){1920 / 2, 1080 / 2});
    sfView_setSize(base->pov, (sfVector2f){(1920), (1080)});
    sfRenderWindow_setView(base->win, base->pov);
    sfClock_restart(base->player.cl);
    srand(time(NULL));
    base->fstate.player = &base->player;
    base->fstate.enemy = en;
    set_hp(&base->fstate);
    replace_sp_tex(bg_path, &base->fstate.bg);
    play_anime("idle", &base->fstate.enemy->s);
    play_anime("idle", &base->fstate.player->s);
    sfMusic_stop(base->over_mus);
    sfMusic_play(mus);
    fight(base);
    base->fstate.start = false;
    sfMusic_play(base->over_mus);
    sfMusic_stop(base->vi_mus);
}

void set_hp(fight_t *f)
{
    my_memset(f->hp_dis.enter, 9, 0);
    my_memset(f->hp_dis.ref, 9, 0);
    my_strcpy(f->hp_dis.enter, "hp:");
    add_nb(f->player->stats.hp, f->hp_dis.enter);
    add_char(f->hp_dis.enter, '/', 9);
    add_nb(f->player->stats.maxhp, f->hp_dis.enter);
    my_strcpy(f->hp_dis.ref, "hp:");
    add_nb(f->enemy->stats.hp, f->hp_dis.ref);
    add_char(f->hp_dis.ref, '/', 9);
    add_nb(f->enemy->stats.maxhp, f->hp_dis.ref);
    sfText_setString(f->hp_dis.ent, f->hp_dis.enter);
    sfText_setString(f->hp_dis.r, f->hp_dis.ref);
}

void draw_fstate(fight_t *f, sfRenderWindow *win)
{
    draw_sprite(win, f->bg);
    sfRenderWindow_drawText(win, f->ent.r, NULL);
    sfRenderWindow_drawText(win, f->ent.ent, NULL);
    draw_sprite(win, f->enemy->s.sp);
    draw_sprite(win, f->player->s.sp);
    for (int i = 0; i < 2; i++) {
        if (f->spell[i].bg.visible) {
            draw_sprite(win, f->spell[i].bg);
            sfRenderWindow_drawText(win, f->spell[i].txt, NULL);
        }
    }
    sfRenderWindow_drawText(win, f->hp_dis.r, NULL);
    sfRenderWindow_drawText(win, f->hp_dis.ent, NULL);
}
