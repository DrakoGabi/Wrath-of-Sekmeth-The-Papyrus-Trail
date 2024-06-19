/*
** EPITECH PROJECT, 2023
** isupper
** File description:
** isupper
*/

#include "../../include/my.h"

int my_str_isupper(char *str)
{
    if (my_strlen(str) == 0)
        return 0;
    for (int i = 0; str[i]; i++) {
        if (!is_upcase(str[i]))
            return 0;
    }
    return 1;
}
