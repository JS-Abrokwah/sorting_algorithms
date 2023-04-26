#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * sift_down - Heapifies a binary tree rooted at a given index
 *
 * @array: Pointer to the array to sort
 * @size: Number of elements in the array
 * @index: Index to start the heapification from
 * @heap_size: The heap size
 *
 */

void sift_down(int *array, size_t size, size_t index, size_t heap_size)
{
    size_t max = index, left = (2 * index) + 1, right = (2 * index) + 2;
    int temp;

    if (left < heap_size && array[left] > array[max])
        max = left;

    if (right < heap_size && array[right] > array[max])
        max = right;

    if (max != index)
    {
        temp = array[index];
        array[index] = array[max];
        array[max] = temp;

        heap_sort(array, size);
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the heap sort algorithm
 *
 * @array: Pointer to the array to sort
 * @size: Number of elements in the array
 *
 */
void heap_sort(int *array, size_t size)
{
    int temp;
    size_t i, heap_size = size;

    for (i = (size / 2) - 1; (int)i >= 0; i--)
        sift_down(array, size, i, heap_size);

    for (i = size - 1; i > 0; i--)
    {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;

        heap_size--;
        sift_down(array, size, 0, heap_size);
    }
}
