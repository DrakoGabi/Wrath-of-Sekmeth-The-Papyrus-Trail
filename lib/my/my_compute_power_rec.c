/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday05-tessy.grondin
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (nb * nb > 2147483647)
        return 1;
    if (p == 0)
        return 1;
    if (p == 1)
        return nb;
    return my_compute_power_rec((nb * nb), (p -1));
}
