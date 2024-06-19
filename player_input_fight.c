/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** player_input_fight
*/

#include "rpg.h"

void set_answer(char src[9], int len)
{
    char ref[] = "abcdefghijklmnopqrstuvwxyz";

    my_memset((char *)src, 9, 0);
    for (int i = 0; i < len; i++)
        src[i] = ref[rand() % 26];
}
