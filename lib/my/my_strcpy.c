/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday06-tessy.grondin
** File description:
** my_strcpy
*/

#include "../../include/my.h"

char **my_tabcpy(char **tab)
{
    char **res = NULL;

    for (int i = 0; tab && tab[i]; i++)
        res = tab_append(res, tab[i]);
    return res;
}

char *my_strcpy(char *dest, char const *src)
{
    int len = 0;

    if (!dest)
        return NULL;
    for (; src && src[len]; len++)
        dest[len] = src[len];
    dest[len] = '\0';
    return dest;
}
