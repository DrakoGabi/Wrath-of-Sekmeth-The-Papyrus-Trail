/*
** EPITECH PROJECT, 2023
** printf
** File description:
** my_putfloat_base
*/

#include "../../include/my.h"

int transform_nb_base(double nb, int prec, char const *base)
{
    int len = my_strlen(base);

    for (int i = 0; i < prec + 1; i++)
        nb *= len;
    return nb;
}

int my_putfloat_base(double nb, int prec, char const *base)
{
    int len = my_nblen(nb);
    int trans = transform_nb_base(nb, prec, base);
    char *inter = my_nb_to_string_base(trans, base);
    int res = 0;
    int i = 0;

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
