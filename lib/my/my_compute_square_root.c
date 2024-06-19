/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday05-tessy.grondin
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int i = 1;

    for (; 1;) {
        if (i > 2147483647)
            break;
        if ((i * i) == nb)
            return i;
        if ((i * i) > nb)
            break;
        i++;
    }
    return 0;
}
