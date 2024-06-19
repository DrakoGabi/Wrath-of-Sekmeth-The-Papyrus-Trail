/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday06-tessy.grondin
** File description:
** my_showstr
*/

#include "../../include/my.h"

int my_showstr(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (my_is_printable(str[i]))
            write(1, &str[i], 1);
        if (!my_is_printable(str[i])) {
            write(1, "\\", 1);
            my_putnbr_base((int)str[i], "0123456789abcdef");
        }
    }
    return 0;
}
