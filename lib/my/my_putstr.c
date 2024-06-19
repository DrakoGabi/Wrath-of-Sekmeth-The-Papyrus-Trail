/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday04-tessy.grondin
** File description:
** my_putstr
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    if (str == NULL)
        return my_putstr("(null)");
    for (; str[i]; i++)
        my_putchar(str[i]);
    return i;
}
