/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** str to tab
*/

#include "../../include/my.h"

char **tab_append(char **src, char *add)
{
    char **res = NULL;
    int i = 0;

    res = malloc(sizeof(char *) * (my_tablen(src) + 2));
    for (; src && src[i]; i++)
        res[i] = my_strdup(src[i]);
    res[i] = my_strdup(add);
    res[i + 1] = NULL;
    freer(src);
    return res;
}

char *my_word_array_to_str(char **array, char delim)
{
    char *res = NULL;
    char *tmp = NULL;

    if (!array)
        return NULL;
    res = my_strdup(array[0]);
    for (int i = 1; array[i]; i++) {
        res = my_append(res, delim);
        tmp = my_str_concat(res, array[i]);
        res = my_fstrdup(res, tmp);
        tmp = can_free(tmp);
    }
    can_free(tmp);
    return res;
}

char **my_str_to_word_array(char *str, char *delim)
{
    char **res = NULL;

    str = my_strtok(str, delim);
    for (; str;) {
        if (str[0] != '\0')
            res = tab_append(res, str);
        str = my_strtok(NULL, delim);
    }
    return res;
}
