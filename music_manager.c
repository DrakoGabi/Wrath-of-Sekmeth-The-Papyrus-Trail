/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** music_manager
*/

#include "rpg.h"

sfMusic *get_music(char *src)
{
    sfMusic *res = sfMusic_createFromFile(src);

    sfMusic_setLoop(res, sfTrue);
    return res;
}

void stop_combat_music(base_t *b)
{
    if (sfMusic_getStatus(b->en_mus) == sfPlaying)
        sfMusic_stop(b->en_mus);
    if (sfMusic_getStatus(b->ib_mus) == sfPlaying)
        sfMusic_stop(b->ib_mus);
    if (sfMusic_getStatus(b->ba_mus) == sfPlaying)
        sfMusic_stop(b->ba_mus);
    if (sfMusic_getStatus(b->th_mus) == sfPlaying)
        sfMusic_stop(b->th_mus);
}

void get_all_music(base_t *b)
{
    b->over_mus = get_music(O_MUS);
    b->en_mus = get_music(S_MUS);
    b->ib_mus = get_music(I_MUS);
    b->ba_mus = get_music(B_MUS);
    b->th_mus = get_music(T_MUS);
    b->vi_mus = get_music(V_MUS);
    b->go_mus = get_music(G_MUS);
    b->ge_mus = get_music(GEN_MUS);
    b->cu_mus = get_music(C_MUS);
}

void destroy_all_music(base_t *b)
{
    sfMusic_destroy(b->over_mus);
    sfMusic_destroy(b->en_mus);
    sfMusic_destroy(b->ib_mus);
    sfMusic_destroy(b->ba_mus);
    sfMusic_destroy(b->th_mus);
    sfMusic_destroy(b->vi_mus);
    sfMusic_destroy(b->go_mus);
    sfMusic_destroy(b->ge_mus);
    sfMusic_destroy(b->cu_mus);
}
