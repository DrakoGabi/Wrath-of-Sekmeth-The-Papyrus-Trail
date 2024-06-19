/*
** EPITECH PROJECT, 2023
** isalpha
** File description:
** islpha
*/

#include "../../include/my.h"

bool my_isalpha(char c)
{
    if (!is_low_case(c) && !is_upcase(c))
        return false;
    return true;
}

int my_str_isalpha(char *str)
{
    if (my_strlen(str) == 0)
        return 0;
    for (int i = 0; str[i]; i++)
        if (!is_low_case(str[i]) && !is_upcase(str[i]))
            return 0;
    return 1;
}
