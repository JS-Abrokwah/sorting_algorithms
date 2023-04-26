#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int partition(int *array, int low, int high, size_t size);
void quicksort_hoare_recursive(int *array, int low, int high, size_t size);
void swap_ints(int *a, int *b);

/**
 * partition - function that partitions an array according to the Hoare scheme
 * @array: pointer to the array to partition
 * @low: index of the first element of the partition
 * @high: index of the last element of the partition
 * @size: size of the array
 * Return: index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		int temp = array[i];

		array[i] = array[j];
		array[j] = temp;

		size_t k;

		for (k = 0; k < size; k++)
			printf("%d%s", array[k], k == size - 1 ? "\n" : ", ");
	}
}

/**
 * quicksort_hoare_recursive - function that sorts an array of integers using
 * the quicksort algorithm and the Hoare partition scheme recursively
 * @array: pointer to the array to sort
 * @low: index of the first element of the partition to sort
 * @high: index of the last element of the partition to sort
 * @size: size of the array
 */
void quicksort_hoare_recursive(int *array, int low, int high, size_t size)
{

	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		quicksort_hoare_recursive(array, low, pivot_index, size);
		quicksort_hoare_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort_hoare - function that sorts an array of integers using the
 * quicksort algorithm and the Hoare partition scheme
 * @array: pointer to the array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_hoare_recursive(array, 0, size - 1, size);
}

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
