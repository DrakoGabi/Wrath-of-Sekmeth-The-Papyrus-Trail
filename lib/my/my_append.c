/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** my_append
*/

#include "../../include/my.h"

char *my_append(char *str, char c)
{
    int i = 0;
    char *res;

    if (str == NULL) {
        res = malloc(sizeof(char) * 2);
        res[0] = c;
        res[1] = '\0';
        return res;
    }
    res = malloc(sizeof(char) * (my_strlen(str) + 2));
    for (; str[i]; i++)
        res[i] = str[i];
    res[i] = c;
    res[i + 1] = '\0';
    free(str);
    return res;
}

char **my_tabpop(char **src, int index)
{
    char **res = NULL;

    if (!src)
        return NULL;
    if (my_tablen(src) == 1)
        return freer(src);
    for (int i = 0; src[i]; i++)
        if (i != index)
            res = tab_append(res, src[i]);
    freer(src);
    return res;
}

char *my_pop(char *str, int index)
{
    char *res = NULL;

    for (int i = 0; str[i]; i++) {
        if (i != index)
            res = my_append(res, str[i]);
    }
    free(str);
    return res;
}

char *my_unappend(char *str)
{
    char *res = NULL;

    for (int i = 1; str[i]; i++)
        res = my_append(res, str[i - 1]);
    free(str);
    return res;
}

int *append_int(int *src, int add)
{
    int i = 0;
    int *res = NULL;

    res = malloc(sizeof(int) * (my_intlen(src) + 2));
    for (; src && src[i] != -1; i++)
        res[i] = src[i];
    res[i] = add;
    res[i + 1] = -1;
    can_free(src);
    return res;
}
