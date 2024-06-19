/*
** EPITECH PROJECT, 2022
** B-CPE-101-RUN-1-1-myprintf-florian.dajon
** File description:
** my_len
*/

#include "../../include/my.h"

int my_nblen(int nb)
{
    int i = 1;

    for (int p = 1; (nb / p) > 9; i++)
        p *= 10;
    return i;
}

int my_tablen(char **src)
{
    int i = 0;

    for (; src && src[i]; i++);
    return i;
}

int my_intlen(int *src)
{
    int i = 0;

    for (; src && src[i] != -1; i++);
    return i;
}
