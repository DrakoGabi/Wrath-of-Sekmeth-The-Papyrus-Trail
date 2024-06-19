/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday05-tessy.grondin
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    for (int i = 2; i != nb; i++) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}
