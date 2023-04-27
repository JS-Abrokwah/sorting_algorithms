#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void merge_subarr(int *sub, int *buf, size_t frt, size_t mid,
		size_t back);
void merge_sort_recursive(int *sub, int *buf, size_t frt, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - sort a subarray of integers.
 * @sub: A subarray of an array of integers to sort.
 * @buf: A buffer to store the sorted subarray.
 * @frt: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *sub, int *buf, size_t frt, size_t mid, size_t back)
{
	size_t a, b, c = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + frt, mid - frt);

	printf("[right]: ");
	print_array(sub + mid, back - mid);

	for (a = frt, b = mid; a < mid && b < back; c++)
		buf[c] = (sub[a] < sub[b]) ? sub[a++] : sub[b++];
	for (; a < mid; a++)
		buf[c++] = sub[a];
	for (; b < back; b++)
		buf[c++] = sub[b];
	for (a = frt, c = 0; a < back; a++)
		sub[a] = buf[c++];

	printf("[Done]: ");
	print_array(sub + frt, back - frt);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion
 * @sub: A subarray of an array of integers to sort.
 * @buf: A buffer to store the sorted result.
 * @frt: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_sort_recursive(int *sub, int *buf, size_t frt, size_t back)
{
	size_t mid;

	if (back - frt > 1)
	{
		mid = frt + (back - frt) / 2;
		merge_sort_recursive(sub, buf, frt, mid);
		merge_sort_recursive(sub, buf, mid, back);
		merge_sort_recursive(sub, buf, frt, back);
	}
}

/**
 * merge_sort - sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	merge_sort_recursive(array, buf, 0, size);

	free(buf);
}
