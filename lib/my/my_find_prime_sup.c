/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday05-tessy.grondin
** File description:
** my_find_prime_sup
*/

#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    int res = nb + 1;

    if (my_is_prime(nb))
        return nb;
    for (; !(my_is_prime(res));)
        res++;
    return res;
}
