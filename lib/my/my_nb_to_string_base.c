/*
** EPITECH PROJECT, 2023
** printf
** File description:
** my_nb_to_string_base
*/

#include "../../include/my.h"

char *my_nb_to_string_base(long nbr, char const *base)
{
    long power = my_strlen(base);
    int tmp = 0;
    char *res = NULL;

    if (nbr < 0) {
        nbr *= -1;
        res = my_append(res, '-');
    }
    if (nbr < power)
        return my_append(res, base[nbr]);
    for (; nbr / power > my_strlen(base) - 1;)
        power *= my_strlen(base);
    for (; power >= 1;) {
        tmp = nbr / power;
        res = my_append(res, base[tmp]);
        nbr %= power;
        power /= my_strlen(base);
    }
    return res;
}

char *my_nb_to_string(long nbr)
{
    return my_nb_to_string_base(nbr, "0123456789");
}
