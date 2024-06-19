/*
** EPITECH PROJECT, 2023
** strstr
** File description:
** strstr
*/

#include "../../include/my.h"

char *my_strstr(char *str, char const *to_find)
{
    int len = my_strlen(to_find);
    int char_found = 0;
    int str_len = my_strlen(str);
    int found = -1;

    if (str_len < len)
        return NULL;
    for (int i = 0; i < str_len; i++) {
        if (str[i] == to_find[char_found]) {
            found = i;
            char_found++;
        }
        if (str[i] != to_find[char_found])
            char_found = 0;
        if (char_found == len - 1)
            break;
    }
    if (char_found != len - 1)
        return NULL;
    return str + found - len - 1;
}
