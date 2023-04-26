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
	ssize_t current = lo, j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (array[current] != array[j])
			{
				swap(array, current, j);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[hi])
	{
		swap(array, current, last);
		print_array(array, size);
	}
	return (current);
}

/**
 * swap - swaps two elements in an array
 * @a: first element
 * @b: second element
 */
void swap(int array, ssize a, ssize b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}
