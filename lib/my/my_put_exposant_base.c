/*
** EPITECH PROJECT, 2023
** printf
** File description:
** my_put_exposant_base
*/

#include "../../include/my.h"

int my_put_exposant_base(double nb, int prec, char ex, char const *base)
{
    int step = 0;
    int res = 0;
    int len = my_strlen(base);

    for (; nb > len || nb < 1;) {
        step += (nb > len) ? 1 : -1;
        nb = (nb > len) ? (nb / len) : (nb * len);
    }
    res = my_putfloat_base(nb, prec, base) + my_putchar(ex);
    if (step > 0)
        res += my_putchar('+');
    return res + my_put_nbr(step);
}
