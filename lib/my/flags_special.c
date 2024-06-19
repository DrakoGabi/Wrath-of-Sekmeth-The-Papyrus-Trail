/*
** EPITECH PROJECT, 2023
** printf
** File description:
** flags_special
*/

#include "../../include/my.h"

int flagm(va_list *ap, int prec, int count)
{
    int *ex = chosen_exit();

    *ex = 2;
    (void)ap;
    (void)prec;
    (void)count;
    return 0;
}

int flagn(va_list *ap, int prec, int count)
{
    int *ex = va_arg(*ap, int *);

    *ex = count - 1;
    (void)ap;
    (void)prec;
    return 0;
}
