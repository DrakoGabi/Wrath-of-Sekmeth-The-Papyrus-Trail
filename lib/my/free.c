/*
** EPITECH PROJECT, 2023
** navy
** File description:
** free
*/

#include "../../include/my.h"

void *can_free(void *ptr)
{
    if (ptr)
        free(ptr);
    return NULL;
}

void *freer(char **tab)
{
    for (int i = 0; tab && tab[i]; i++)
        can_free(tab[i]);
    return can_free(tab);
}

void *free_int(int **nb_tab)
{
    if (nb_tab == NULL || nb_tab[0] == NULL)
        return NULL;
    for (int i = 0; nb_tab[i]; i++)
        can_free(nb_tab[i]);
    return can_free(nb_tab);
}
