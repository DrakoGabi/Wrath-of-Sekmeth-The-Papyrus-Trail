/*
** EPITECH PROJECT, 2023
** B-CPE-100-RUN-1-1-cpoolday04-tessy.grondin
** File description:
** my_sort_int_array
*/

#include "../../include/my.h"

int find_smallest(int *array, int size, int start)
{
    int smallest = start;

    for (int i = start + 1; i < size; i++) {
        if (array[smallest] > array[i])
            smallest = i;
    }
    return smallest;
}

void my_sort_int_array(int *array, int size)
{
    int last_sorted = 0;
    int to_swap = 0;

    if (array == NULL || size <= 0)
        return;
    for (; last_sorted < size;) {
        to_swap = find_smallest(array, size, last_sorted);
        my_swap(&array[to_swap], &array[last_sorted]);
        last_sorted++;
    }
}
