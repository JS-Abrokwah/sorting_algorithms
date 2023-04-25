#include <stdio.h>
#include <stdlib>
#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - helper function for quick_sort
 * @array: pointer to the first element of the array
 * @lo: starting index of the partition to be sorted
 * @hi: ending index of the partition to be sorted
 * @size: number of elements in the array
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
    if (lo < hi)
    {
        int p = lomuto_partition(array, lo, hi, size);
        quick_sort_helper(array, lo, p - 1, size);
        quick_sort_helper(array, p + 1, hi, size);
    }
}

/**
 * lomuto_partition - partitions an array using the Lomuto partition scheme
 * @array: pointer to the first element of the array
 * @lo: starting index of the partition to be sorted
 * @hi: ending index of the partition to be sorted
 * @size: number of elements in the array
 *
 * Return: index of the pivot element
 */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
    int pivot = array[hi];
    int i = lo - 1;

    for (int j = lo; j < hi; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(array + i, array + j);
            print_array(array, size);
        }
    }

    swap(array + (i + 1), array + hi);
    print_array(array, size);

    return i + 1;
}

/**
 * swap - swaps two elements in an array
 * @a: pointer to the first element
 * @b: pointer to the second element
 */
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

