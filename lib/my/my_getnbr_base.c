/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday06-tessy.grondin
** File description:
** my_getnbr_base
*/

#include "../../include/my.h"

int place(char const *str, char c)
{
    int i = 0;

    for (; str[i] && c != str[i]; i++);
    return i;
}

int my_isbase(char c, char const *base)
{
    for (int i = 0; base[i]; i++) {
        if (c == base[i])
            return 1;
    }
    return 0;
}

int my_getnbr_base(char const *str, char const *base)
{
    int i = 0;
    int minus = 0;
    int nb = 0;
    int len_base = my_strlen(base);

    if (len_base == 0)
        return 0;
    for (; str[i] == '-' || str[i] == '+' || my_isbase(str[i], base);) {
        if (my_isbase(str[i], base))
            nb = nb * len_base + str[i] - place(base, str[i]);
        if (str[i] == '-')
            minus = minus + 1;
        if (my_isbase(str[i], base) == 1 && my_isbase(str[i + 1], base) == 0)
            break;
        i = i + 1;
    }
    if (minus % 2 == 1)
        nb = -nb;
    return nb;
}
