/*
** EPITECH PROJECT, 2023
** printf
** File description:
** my_put_exposant
*/

#include "../../include/my.h"

int print_ex(int ex)
{
    if (ex < 10 && ex > 0)
        return my_putchar('0') + my_put_nbr(ex);
    else if (ex < 0 && ex > -10)
        return my_putstr("-0") + my_put_nbr(-ex);
    return my_put_nbr(ex);
}

int my_put_exposant(double nb, int prec, char ex)
{
    int step = 0;
    int res = 0;

    for (; nb > 10 || nb < 1;) {
        step += (nb > 10) ? 1 : -1;
        nb = (nb > 10) ? (nb / 10) : (nb * 10);
    }
    res = my_putfloat(nb, prec) + my_putchar(ex);
    if (step > 0)
        res += my_putchar('+');
    return res + print_ex(step);
}
