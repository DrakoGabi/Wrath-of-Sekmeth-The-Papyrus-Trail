/*
** EPITECH PROJECT, 2024
** navy
** File description:
** my_sort_word_array
*/

#include "../../include/my.h"

int find_smallest_word(char **array)
{
    int smallest = 0;

    for (int i = 1; array[i]; i++)
        if (my_strcasecmp(array[smallest], array[i]) == 1)
            smallest = i;
    return smallest;
}

char **my_sort_word_array(char **array)
{
    int to_add = 0;
    char **res = NULL;

    for (; array;) {
        to_add = find_smallest_word(array);
        res = tab_append(res, array[to_add]);
        array = my_tabpop(array, to_add);
    }
    return res;
}
