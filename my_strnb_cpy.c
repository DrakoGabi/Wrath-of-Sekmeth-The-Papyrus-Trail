/*
** EPITECH PROJECT, 2024
** my
** File description:
** my_strnb_cpy
*/

#include "my.h"

char *my_strnb_cpy(int nbr, char *dest)
{
    int power = 10;
    int tmp = 0;
    int pos = my_strlen(dest);

    if (nbr < power) {
        dest[pos] = nbr + 48;
        return dest;
    }
    for (; nbr / power > 10 - 1;)
        power *= 10;
    for (; power >= 1; pos++) {
        tmp = nbr / power;
        dest[pos] = tmp + 48;
        nbr %= power;
        power /= 10;
    }
    return dest;
}
