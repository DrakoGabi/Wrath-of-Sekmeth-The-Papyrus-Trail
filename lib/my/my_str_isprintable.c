/*
** EPITECH PROJECT, 2023
** printable
** File description:
** printable
*/

#include "../../include/my.h"

int my_is_printable(char c)
{
    if (c < 32 && c > 126)
        return 0;
    return 1;
}

int my_str_isprintable(char *str)
{
    if (my_strlen(str) == 0)
        return 0;
    for (int i = 0; str[i]; i++) {
        if (!my_is_printable(str[i]))
            return 0;
    }
    return 1;
}
