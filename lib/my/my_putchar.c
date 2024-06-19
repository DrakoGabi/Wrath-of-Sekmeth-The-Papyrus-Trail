/*
** EPITECH PROJECT, 2023
** putchar
** File description:
** putchar
*/

#include "../../include/my.h"

int my_putchar(char c)
{
    return write(*chosen_exit(), &c, 1);
}
