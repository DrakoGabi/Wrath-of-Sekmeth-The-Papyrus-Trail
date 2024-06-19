/*
** EPITECH PROJECT, 2023
** printf
** File description:
** flags_base
*/

#include "../../include/my.h"

int flago(va_list *ap, int prec, int count)
{
    (void)prec;
    (void)count;
    return my_putnbr_base(va_arg(*ap, int), "01234567");
}

int flagx(va_list *ap, int prec, int count)
{
    (void)prec;
    (void)count;
    return my_putnbr_base(va_arg(*ap, int), "0123456789abcdef");
}

int flag_x(va_list *ap, int prec, int count)
{
    (void)prec;
    (void)count;
    return my_putnbr_base(va_arg(*ap, int), "0123456789ABCDEF");
}

int flagb(va_list *ap, int prec, int count)
{
    (void)prec;
    (void)count;
    return my_putnbr_base(va_arg(*ap, int), "01");
}
