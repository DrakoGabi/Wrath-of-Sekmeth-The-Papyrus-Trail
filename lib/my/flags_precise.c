/*
** EPITECH PROJECT, 2023
** printf
** File description:
** flags_precise
*/

#include "../../include/my.h"

int flagf(va_list *ap, int prec, int count)
{
    (void)count;
    return my_putfloat(va_arg(*ap, double), prec);
}

int flage(va_list *ap, int prec, int count)
{
    (void)count;
    return my_put_exposant(va_arg(*ap, double), prec, 'e');
}

int flag_e(va_list *ap, int prec, int count)
{
    (void)count;
    return my_put_exposant(va_arg(*ap, double), prec, 'E');
}

int flaga(va_list *ap, int prec, int count)
{
    (void)count;
    (void)prec;
    return my_put_flaga(va_arg(*ap, double), 0);
}

int flag_a(va_list *ap, int prec, int count)
{
    (void)prec;
    (void)count;
    return my_put_flaga(va_arg(*ap, double), 1);
}
