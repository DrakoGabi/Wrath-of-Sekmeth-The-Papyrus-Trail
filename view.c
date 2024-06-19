/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-gabriel.villemonte
** File description:
** view
*/

#include "rpg.h"

sfView *create_view(void)
{
    sfView *res = sfView_create();

    sfView_setCenter(res, (sfVector2f){620, 1500});
    sfView_setSize(res, (sfVector2f){(30 * 16), (20 * 16)});
    return res;
}

void destroy_view(sfView *res)
{
    sfView_destroy(res);
}
