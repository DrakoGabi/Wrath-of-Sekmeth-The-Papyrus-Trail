/*
** EPITECH PROJECT, 2024
** lib/my
** File description:
** my_realloc
*/

#include "../../include/my.h"

void *my_realloc(size_t size, void *ptr)
{
    can_free(ptr);
    return malloc(size);
}
