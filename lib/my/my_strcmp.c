/*
** EPITECH PROJECT, 2023
** strcmp
** File description:
** compare strings
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    if (len1 == 0 && len2 == 0)
        return 0;
    if (len1 == 0)
        return -1;
    if (len2 == 0)
        return 1;
    for (int i = 0; s1[i] && s2[i]; i++) {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    if (len1 < len2)
        return -1;
    if (len1 > len2)
        return 1;
    return 0;
}

int my_strcasecmp(char const *s1, char const *s2)
{
    char *case1 = my_strdup(s1);
    char *case2 = my_strdup(s2);
    int res = 0;

    case1 = my_strlowcase(case1);
    case2 = my_strlowcase(case2);
    res = my_strcmp(case1, case2);
    can_free(case1);
    can_free(case2);
    return res;
}
