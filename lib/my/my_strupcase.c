/*
** EPITECH PROJECT, 2023
** strupcase
** File description:
** everything in upcase
*/

#include "../../include/my.h"

int is_low_case(char c)
{
    if (c >= 'a' && c <= 'z')
        return 1;
    return 0;
}

char *my_strupcase(char *str)
{
    if (my_strlen(str) == 0)
        return str;
    for (int i = 0; str[i]; i++) {
        if (is_low_case(str[i]))
            str[i] -= 32;
    }
    return str;
}
