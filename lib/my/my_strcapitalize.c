/*
** EPITECH PROJECT, 2023
** capitalize
** File description:
** upcase only on first letter
*/

#include "../../include/my.h"

int is_alphanum(char c)
{
    if (c <= 'z' && c >= 'a')
        return 1;
    if (c <= 'Z' && c >= 'A')
        return 1;
    if (c <= '9' && c >= '0')
        return 1;
    if (c == '_')
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    int start = 0;

    if (my_strlen(str) == 0)
        return str;
    str = my_strlowcase(str);
    for (int i = 0; str[i]; i++) {
        if (!is_alphanum(str[i]))
            start = 1;
        if (start == 1 && is_low_case(str[i]))
            str[i] -= 32;
        if (is_alphanum(str[i]))
            start = 0;
    }
}
