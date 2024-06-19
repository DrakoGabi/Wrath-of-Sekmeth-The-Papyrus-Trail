/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday06-tessy.grondin
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = 0;
    int max = 0;

    for (; src[len] && src[max]; len++) {
        if (max == n)
            break;
        max++;
        dest[len] = src[len];
    }
    if (max < n)
        dest[len] = '\0';
    return dest;
}
