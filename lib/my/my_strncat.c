/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** i = "dest" +"src"
*/

#include "../../include/my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int i = my_strlen(dest);

    for (int j = 0; j != n; j++)
        dest[i + j] = src[j];
    return dest;
}
