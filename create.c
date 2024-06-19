/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** create
*/

#include "rpg.h"

sfText *set_text(char *str, sfFont *font, sfColor col)
{
    sfText *res = sfText_create();

    sfText_setFont(res, font);
    sfText_setFillColor(res, col);
    sfText_setString(res, str);
    return res;
}

entry_t create_ent(sfFont *font)
{
    entry_t res = {0};

    res.ent = set_text("", font, sfRed);
    res.r = set_text("", font, sfRed);
    return res;
}

void make_select(fight_t *f, sfFont *font)
{
    f->spell[0].bg = create_sprite(SELECT_BG);
    f->spell[1].bg = create_sprite(SELECT_BG);
    f->spell[0].len = 5;
    f->spell[1].len = 8;
    f->spell[0].txt = set_text("claw 5", font, sfRed);
    f->spell[1].txt = set_text("breath 8", font, sfRed);
    set_sp_pos((sfVector2f){750, 800}, &f->spell[0].bg);
    set_sp_pos((sfVector2f){950, 800}, &f->spell[1].bg);
    set_sp_scale((sfVector2f){1.5, 1.5}, &f->spell[0].bg);
    set_sp_scale((sfVector2f){1.5, 1.5}, &f->spell[1].bg);
    sfText_setPosition(f->spell[0].txt, (sfVector2f){770, 820});
    sfText_setPosition(f->spell[1].txt, (sfVector2f){970, 820});
    f->spell[0].activ = true;
}

fight_t create_fight(sfFont *font)
{
    fight_t res = {0};

    res.ent = create_ent(font);
    res.hp_dis = create_ent(font);
    res.bg = create_sprite(NULL);
    set_sp_scale((sfVector2f){2, 2.4}, &res.bg);
    sfText_setPosition(res.hp_dis.ent, (sfVector2f){1500, 200});
    sfText_setPosition(res.hp_dis.r, (sfVector2f){500, 200});
    sfText_setPosition(res.ent.ent, (sfVector2f){900, 500});
    sfText_setPosition(res.ent.r, (sfVector2f){900, 500});
    sfText_setFillColor(res.ent.ent, sfGreen);
    sfText_setCharacterSize(res.ent.ent, 50);
    sfText_setCharacterSize(res.ent.r, 50);
    make_select(&res, font);
    res.spell[1].bg.visible = false;
    res.vic = create_victory(font);
    return res;
}
