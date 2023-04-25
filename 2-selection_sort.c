#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using the
 * Selection sort algorithm and prints the array after each swap
 *
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */

void selection_sort(int *array, size_t size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		size_t min_index = i;

		for (size_t j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}

		if (min_index != i)
		{
			int temp = array[i];

			array[i] = array[min_index];
			array[min_index] = temp;

			print_array(array, size);
		}
	}
}
