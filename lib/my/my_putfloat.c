/*
** EPITECH PROJECT, 2023
** printf
** File description:
** my_putfloat
*/

#include "../../include/my.h"

long transform_nb2(double nb, int prec)
{
    for (; my_nblen(nb) < prec; nb *= 10);
    return nb;
}

long transform_nb(double nb, int prec)
{
    for (int i = 0; i < prec + 1; i++)
        nb *= 10;
    return nb;
}

int my_putfloat(double nb, int prec)
{
    int len = my_nblen(nb);
    long trans = transform_nb(nb, prec);
    char *inter = my_nb_to_string(trans);
    int res = 0;
    int i = 0;

    if (!inter)
        return 0;
    for (; i < len; i++)
        res += my_putchar(inter[i]);
    if (prec == 0)
        return res;
    res += my_putchar('.');
    for (; inter[i + 1]; i++)
        res += my_putchar(inter[i]);
    free(inter);
    return res;
}
