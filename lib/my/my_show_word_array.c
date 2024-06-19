/*
** EPITECH PROJECT, 2022
** my_show_word_array.c
** File description:
** display word array as a list
*/

#include "../../include/my.h"

void put_spe_chara(char *str)
{
    if (str[0] == '\0')
        my_putstr("\\0");
    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n') {
            my_putstr("\\n");
            continue;
        }
        if (str[i] == '\t') {
            my_putstr("\\t");
            continue;
        }
        my_putchar(str[i]);
    }
}

int my_show_word_array(char *const *tab)
{
    int count = 0;

    if (is_mt((char **)tab)) {
        my_putstr("||\n");
        return 0;
    }
    for (int i = 0; tab[i]; i++) {
        my_putchar('|');
        put_spe_chara(tab[i]);
        my_putchar('|');
        my_putchar('\n');
        count++;
    }
    return count;
}
