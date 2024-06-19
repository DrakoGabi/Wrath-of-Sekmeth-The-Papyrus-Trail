/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** just_pressed
*/

#include "rpg.h"

bool just_pressed(base_t *states, int key)
{
    if (states->key_states[key] == 0 && sfKeyboard_isKeyPressed(key)) {
        states->key_states[key] = 1;
        return true;
    } else
        states->key_states[key] = sfKeyboard_isKeyPressed(key);
    return false;
}
