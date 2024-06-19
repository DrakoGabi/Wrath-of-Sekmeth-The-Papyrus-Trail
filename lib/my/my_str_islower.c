/*
** EPITECH PROJECT, 2023
** islower
** File description:
** islower
*/

#include "../../include/my.h"

int my_str_islower(char *str)
{
    if (my_strlen(str) == 0)
        return 0;
    for (int i = 0; str[i]; i++) {
        if (!is_low_case(str[i]))
            return 0;
    }
    return 1;
}
