/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** my_strtok
*/

#include "../../include/my.h"

bool is_delim(char c, char *delim)
{
    if (!c)
        return true;
    for (int i = 0; delim && delim[i]; i++)
        if (c == delim[i])
            return true;
    return false;
}

char *my_strtok(char *src, char *delim)
{
    char *res = NULL;
    static char *backup = NULL;
    static bool yes = true;

    if (src) {
        res = src;
        yes = true;
    } else
        res = backup;
    if (!yes)
        return NULL;
    for (int i = 0; res && res[i]; i++) {
        if (is_delim(res[i], delim)) {
            res[i] = '\0';
            backup = res + i + 1;
            return res;
        }
    }
    yes = false;
    return res;
}
