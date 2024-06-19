/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday06-tessy.grondin
** File description:
** my_revstr
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int start = 0;
    int end = my_strlen(str) - 1;
    char tmp = 0;

    if (str == NULL || end == 0)
        return str;
    for (; start < end;) {
        tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;
        start++;
        end--;
    }
    return str;
}
