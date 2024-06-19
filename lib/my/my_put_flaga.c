/*
** EPITECH PROJECT, 2023
** printf
** File description:
** my_put_flaga
*/

#include "../../include/my.h"

char incase(char c, int char_type)
{
    if (is_upcase(c) && char_type == 1)
        return c + 32;
    return c;
}

int write_hex(char *bin, int char_type)
{
    for (int i = 0; i < 16; i++)
        if (!my_strncmp(convert[i].bin, bin, 4))
            return my_putchar(incase(convert[i].hex, char_type));
    return 0;
}

int conver_to_hex(char *bin, int ex, int sign, int char_type)
{
    int res = 0;

    if (sign == -1)
        res = my_putchar('-');
    res += my_putchar('0') + my_putchar(incase('x', char_type));
    res += my_putstr("1.");
    for (int i = 0; bin && bin[i]; i += 4)
        res += write_hex(bin + i, char_type);
    res += my_putchar(incase('p', char_type));
    if (sign == 0)
        res += my_putchar('+');
    res += my_put_nbr(ex);
    free(bin);
    return res;
}

int my_put_flaga(double nb, int char_type)
{
    char *inter = NULL;
    int ex = 0;
    nbru_t nbr;
    int sign = 0;
    unsigned long to_put = 0;

    nbr.doub = nb;
    sign = (nbr.lon & (1L << 63)) >> 63;
    ex = (((nbr.lon << 1) & 0xfffff00000000000) >> 53) - 1023;
    nbr.lon <<= 12;
    to_put = nbr.lon;
    for (size_t i = 0; i < 52; ++i) {
        to_put = (unsigned long)nbr.lon;
        to_put = (to_put & (1L << 63));
        to_put >>= 63;
        inter = (to_put == 1) ? my_append(inter, '1') : my_append(inter, '0');
        nbr.lon <<= 1;
    }
    return conver_to_hex(inter, ex, sign, char_type);
}
