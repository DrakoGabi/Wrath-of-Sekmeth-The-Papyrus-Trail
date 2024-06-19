/*
** EPITECH PROJECT, 2023
** printf
** File description:
** my_put_unsigned
*/

#include "../../include/my.h"

int my_put_unsigned(unsigned int nb)
{
    int p = 1;
    int i = 0;

    if (nb > 4294967295) {
        my_putchar('0');
        return 1;
    }
    for (; (nb / p) > 9; p *= 10);
    for (; p >= 1; i++) {
        my_putchar((nb / p) + 48);
        nb %= p;
        p /= 10;
    }
    return i;
}
