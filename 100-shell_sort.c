#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 *              the Shell sort algorithm, using the Knuth sequence
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int temp;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
		print_array(array, size);
		interval /= 3;
	}
}
