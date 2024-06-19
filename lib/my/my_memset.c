/*
** EPITECH PROJECT, 2024
** egypt
** File description:
** my_memset
*/

#include "../../include/my.h"

void my_memset(char *src, int len, char set)
{
    for (int i = 0; src && src[i] && i < len; i++)
        src[i] = set;
}
