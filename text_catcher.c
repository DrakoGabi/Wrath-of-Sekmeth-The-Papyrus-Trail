/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** text_catcher
*/

#include "rpg.h"

void add_char(char str[9], char c, int len)
{
    int i = 0;

    for (; str && str[i] && i < len; i++);
    if (i == 9 || i >= len)
        return;
    str[i] = c;
}

void catch_input(base_t *b, int len)
{
    for (int i = 0; i < 26; i++) {
        if (just_pressed(b, i)) {
            add_char(b->fstate.ent.enter, i + 97, len);
            sfText_setString(b->fstate.ent.ent, b->fstate.ent.enter);
            return;
        }
    }
}

bool player_wait(base_t *b, int len)
{
    float t = sfTime_asSeconds(sfClock_getElapsedTime(b->fstate.player->cl));
    float limit = (float)b->fstate.player->stats.cl;

    if (t <= limit) {
        catch_input(b, len);
        return true;
    }
    sfClock_restart(b->fstate.player->cl);
    return false;
}

int player_attack(base_t *b)
{
    int count = 0;

    if (b->fstate.player->att == 5)
        play_anime("claw", &b->fstate.player->s);
    else
        play_anime("breath", &b->fstate.player->s);
    for (int i = 0; b->fstate.ent.ref[i]; i++)
        if (b->fstate.ent.ref[i] == b->fstate.ent.enter[i])
            count++;
    my_memset((char *)b->fstate.ent.enter, 9, 0);
    set_hp(&b->fstate);
    count += b->fstate.player->stats.atk;
    if (b->fstate.player->inv.equip == ATT_RING)
        count *= 2;
    return count;
}
