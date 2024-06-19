/*
** EPITECH PROJECT, 2023
** printf
** File description:
** my_put_no_trail
*/

#include "../../include/my.h"


int big_nb(char c)
{
    if (c >= '4' && c <= '9')
        return 1;
    return 0;
}

char *backup_str(char *str)
{
    char *backup = my_strdup("1");

    if (!str) {
        free(backup);
        return NULL;
    }
    for (int i = 0; str[i]; i++)
        backup = my_append(backup, str[i]);
    free(str);
    return backup;
}

char *rounding(char *str)
{
    if (!str)
        return NULL;
    for (; str && str[my_strlen(str) - 1] == '0';)
        str = my_unappend(str);
    if (big_nb(str[my_strlen(str) - 1]))
        str[my_strlen(str) - 2]++;
    for (int i = my_strlen(str) - 2; i > 0; i--) {
        if (str[i] == ':') {
            str[i] = '0';
            str[i - 1]++;
        }
    }
    if (str[0] == ':')
        return backup_str(str);
    return str;
}

char *init_inter(long trans)
{
    char *inter = NULL;

    inter = my_nb_to_string(trans);
    inter = rounding(inter);
    return inter;
}

int my_put_no_trail(double nb, int prec)
{
    int len = my_nblen(nb);
    long trans = transform_nb2(nb, prec);
    char *inter = init_inter(trans);
    int res = 0;

    for (int i = 0; i < len; i++) {
        prec--;
        res += my_putchar(inter[i]);
    }
    if (prec == 1) {
        free(inter);
        return res;
    }
    res += my_putchar('.');
    for (int i = len; inter[i] && prec > 1; i++) {
        prec--;
        res += my_putchar(inter[i]);
    }
    free(inter);
    return res;
}
