#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * radix_sort - Sort an array of integers in ascending order using Radix sort
 * algorithm with LSD (Least Significant Digit) approach
 *
 * @array: Array of integers
 * @size: Size of array
 */
void radix_sort(int *array, size_t size)
{
    int i, exp = 1, max_val = 0;
    int *output, *count;

    if (size < 2)
        return;

    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;
    count = malloc(sizeof(int) * 10);
    if (count == NULL)
    {
        free(output);
        return;
    }

    for (i = 0; i < (int) size; i++)
        if (array[i] > max_val)
            max_val = array[i];

    while (max_val / exp > 0)
    {
        for (i = 0; i < 10; i++)
            count[i] = 0;

        for (i = 0; i < (int) size; i++)
            count[(array[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = (int) size - 1; i >= 0; i--)
        {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }

        for (i = 0; i < (int) size; i++)
            array[i] = output[i];

        exp *= 10;

        /* Print the array after each iteration */
        printf("Result at digit %d: ", exp / 10);
        for (i = 0; i < (int) size; i++)
            printf("%d ", array[i]);
        printf("\n");
    }

    free(output);
    free(count);
}

