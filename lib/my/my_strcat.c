/*
** EPITECH PROJECT, 2022
** my_strcat.c
** File description:
** i = "dest" +"src"
*/

#include "../../include/my.h"

char *my_fstr_concat(char *dest, char *s1, char const *s2)
{
    int len = my_strlen(s1);
    int tot = len + my_strlen(s2);

    can_free(dest);
    dest = malloc(tot + 1);
    if (!dest)
        return NULL;
    for (int i = 0; s1 && s1[i]; i++)
        dest[i] = s1[i];
    for (int i = 0; s2 && s2[i]; i++)
        dest[i + len] = s2[i];
    dest[tot] = '\0';
    return dest;
}

char *my_str_concat(char *s1, char const *s2)
{
    int len = my_strlen(s1);
    int tot = len + my_strlen(s2);
    char *res = malloc(tot + 1);

    if (!res)
        return NULL;
    for (int i = 0; s1 && s1[i]; i++)
        res[i] = s1[i];
    for (int i = 0; s2 && s2[i]; i++)
        res[i + len] = s2[i];
    res[tot] = '\0';
    return res;
}

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);

    for (int j = 0; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    return dest;
}
