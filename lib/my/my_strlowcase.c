/*
** EPITECH PROJECT, 2023
** lowcase
** File description:
** lowcase
*/

#include "../../include/my.h"

int is_upcase(char c)
{
    if (c <= 'Z' && c >= 'A')
        return 1;
    return 0;
}

char *my_strlowcase(char *str)
{
    if (str == NULL || my_strlen(str) == 0)
        return str;
    for (int i = 0; str[i]; i++) {
        if (is_upcase(str[i]))
            str[i] += 32;
    }
    return str;
}
