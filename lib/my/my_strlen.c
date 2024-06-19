/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday04-tessy.grondin
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str && str[i]; i++);
    return i;
}
