/*
** EPITECH PROJECT, 2023
** printf
** File description:
** printf_error
*/

#include "../../include/my.h"

int valid_char(char c)
{
    char *ref = "scid%xXobupmfFeEgGnaA.";

    for (int i = 0; ref[i]; i++)
        if (c == ref[i] || my_isnum(ref[i]))
            return 1;
    return 0;
}

int valid_printf_format(char const *format)
{
    for (int i = 0; format[i + 1]; i++) {
        if (format[i] == '%' && !valid_char(format[i + 1]))
            return -1;
        if (format[i] == '%' && format[i + 1] == '%')
            i++;
    }
    return 1;
}
