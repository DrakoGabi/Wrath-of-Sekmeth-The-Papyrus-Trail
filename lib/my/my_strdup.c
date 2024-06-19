/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday08-tessy.grondin
** File description:
** my_strdup
*/

#include "../../include/my.h"

char *my_fstrdup(char *dest, char const *src)
{
    int len = my_strlen(src);

    can_free(dest);
    dest = malloc(sizeof(char) * (len + 1));
    if (!dest || !src)
        return can_free(dest);
    for (int i = 0; src[i]; i++)
        dest[i] = src[i];
    dest[len] = '\0';
    return dest;
}

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *res = malloc(sizeof(char) * (len + 1));

    if (!res || !src)
        return can_free(res);
    for (int i = 0; src[i]; i++)
        res[i] = src[i];
    res[len] = '\0';
    return res;
}

int *my_intdup(int *src)
{
    int len = my_intlen(src);
    int *res = malloc(sizeof(int) * (len + 1));

    if (!res || !src)
        return can_free(res);
    for (int i = 0; src[i] != -1; i++)
        res[i] = src[i];
    res[len] = -1;
    return res;
}
