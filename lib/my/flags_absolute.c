/*
** EPITECH PROJECT, 2023
** printf
** File description:
** flags_absolute
*/

#include "../../include/my.h"

int flagg(va_list *ap, int prec, int count)
{
    (void)count;
    return my_put_no_trail(va_arg(*ap, double), prec);
}

int flag_g(va_list *ap, int prec, int count)
{
    (void)count;
    return my_put_no_trail(va_arg(*ap, double), prec);
}
