#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 *                 Counting sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *count_array, *sorted_array;
	size_t i;
	int max_num = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}

	count_array = malloc(sizeof(int) * (max_num + 1));
	if (!count_array)
		return;
	for (i = 0; i <= (size_t)max_num; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= (size_t)max_num; i++)
		count_array[i] += count_array[i - 1];



	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(count_array);
		return;
	}
	for (i = 0; i < size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}


	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	print_array(count_array, max_num + 2);

	free(count_array);
	free(sorted_array);
}
