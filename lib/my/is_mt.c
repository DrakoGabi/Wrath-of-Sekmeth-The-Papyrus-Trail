/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** is_mt
*/

#include "../../include/my.h"

int is_mt(char **src)
{
    if (src == NULL || src[0] == NULL || src[0][0] == '\0')
        return 1;
    return 0;
}
