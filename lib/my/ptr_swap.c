/*
** EPITECH PROJECT, 2023
** ptr swap
** File description:
** my_swap but better
*/

#include "../../include/my.h"

void ptr_swap(void *ptr1, void *ptr2)
{
    void *ptr3 = ptr1;

    ptr1 = ptr2;
    ptr2 = ptr3;
}
