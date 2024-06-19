/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday06-tessy.grondin
** File description:
** my_putnbr_base
*/

#include "../../include/my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int power = my_strlen(base);
    int tmp = 0;
    int count = 0;

    if (nbr < 0) {
        nbr *= -1;
        count += my_putchar('-');
    }
    if (nbr < power)
        return my_putchar(base[nbr]);
    for (; nbr / power > my_strlen(base) - 1;)
        power *= my_strlen(base);
    for (; power >= 1;) {
        tmp = nbr / power;
        count += my_putchar(base[tmp]);
        nbr %= power;
        power /= my_strlen(base);
    }
    return count;
}
