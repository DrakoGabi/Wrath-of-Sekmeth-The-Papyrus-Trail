/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday03-tessy.grondin
** File description:
** my_isneg
*/

#include "../../include/my.h"

int my_isneg(int n)
{
    char ref = 0;

    if (n < 0)
        ref = 'N';
    else
        ref = 'P';
    write(1, &ref, 1);
    return 0;
}
