/*
** EPITECH PROJECT, 2023
** printf
** File description:
** flags_int
*/

#include "../../include/my.h"

int flagu(va_list *ap, int prec, int count)
{
    unsigned int nb = va_arg(*ap, int);

    (void)prec;
    (void)count;
    return my_put_unsigned(nb);
}

int flagp(va_list *ap, int prec, int count)
{
    int res = my_putstr("0x");

    (void)prec;
    (void)count;
    return res + my_putnbr_base((long)va_arg(*ap, void *), "0123456789abcdef");
}
