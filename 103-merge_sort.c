#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/*
 * merge - a function that merges different objects
 */

void merge(int *array, int *left, int leftSize, int *right, int rightSize)
{
	int i = 0, j = 0, k = 0;

	while (i < leftSize && j < rightSize)
	{
		if (left[i] < right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < leftSize)
		array[k++] = left[i++];

	while (j < rightSize)
		array[k++] = right[j++];
}

/*
 * merge_sort - a function that sort the merge obj
 */

void merge_sort(int *array, size_t size)
{
	if (size < 2)
		return (size);

	int mid = size / 2;

	int *left = (int *)malloc(mid * sizeof(int));
	int *right = (int *)malloc((size - mid) * sizeof(int));

	for (int i = 0; i < mid; i++)
		left[i] = array[i];

	for (int i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);

	merge(array, left, mid, right, size - mid);

	free(left);
	free(right);

	for (int i = 0; i < size; i++)
		printf("%d%s", array[i], i == size - 1 ? "\n" : " ");
}
