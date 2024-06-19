/*
** EPITECH PROJECT, 2023
** printf
** File description:
** flags_mini
*/

#include "../../include/my.h"

int flags(va_list *ap, int prec, int count)
{
    (void)prec;
    (void)count;
    return my_putstr(va_arg(*ap, char *));
}

int flagc(va_list *ap, int prec, int count)
{
    (void)prec;
    (void)count;
    return my_putchar(va_arg(*ap, int));
}

int flagdi(va_list *ap, int prec, int count)
{
    (void)prec;
    (void)count;
    return my_put_nbr(va_arg(*ap, int));
}

int flagmod(va_list *ap, int prec, int count)
{
    (void)prec;
    (void)ap;
    (void)count;
    return my_putchar('%');
}
