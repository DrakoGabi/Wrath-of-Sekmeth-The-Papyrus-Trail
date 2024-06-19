/*
** EPITECH PROJECT, 2023
** strncmp
** File description:
** compare n characters
*/

#include "../../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    if (len1 < n && len2 < n)
        return my_strcmp(s1, s2);
    for (int i = 0; i < n; i++) {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    return 0;
}
