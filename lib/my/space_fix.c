/*
** EPITECH PROJECT, 2024
** lib/my
** File description:
** space_fix
*/

#include "../../include/my.h"

char *make_line(char *current, char *new)
{
    char *res = NULL;

    if (!current)
        return my_strdup(new);
    res = my_fstr_concat(res, my_append(current, ' '), new);
    if (res[0] == '"')
        res = my_pop(res, 0);
    if (res[my_strlen(res) - 1] == '"')
        res = my_unappend(res);
    return res;
}

char **space_fix(char **src)
{
    char **res = NULL;
    char *tmp = NULL;
    bool on = false;

    for (int i = 0; src && src[i]; i++) {
        if (src[i][0] == '"')
            on = true;
        if (src[i][my_strlen(src[i]) - 1] == '"')
            on = false;
        tmp = make_line(tmp, src[i]);
        if (!on) {
            res = tab_append(res, tmp);
            tmp = can_free(tmp);
        }
    }
    freer(src);
    can_free(tmp);
    return res;
}
