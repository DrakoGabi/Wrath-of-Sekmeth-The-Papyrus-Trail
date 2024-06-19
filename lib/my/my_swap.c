/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday04-tessy.grondin
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int c = *(a);

    *a = *(b);
    *b = c;
}
