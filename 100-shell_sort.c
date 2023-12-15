#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm and Knuth sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t knuth_gap;

	if (!array || size < 2)
		return;

	knuth_gap = initial_knuth_gap(size);

	while (knuth_gap > 0)
	{
		if (knuth_gap != 1)
			insertion_sort_gapped(array, size, knuth_gap);
		else
			insertion_sort(array, size);
		print_array(array, size);
		knuth_gap = (knuth_gap - 1) / 3;
	}
}

/**
 * initial_knuth_gap - Computes largest knuth term for shell_sort
 *
 * @size: Number of elements.
 *
 * Return: largest knuth term that is not greater than
 * ceiled value of (@size / 3)
 */
size_t initial_knuth_gap(size_t size)
{
	size_t gap, ceiled_peak;

	ceiled_peak = size / 3;
	if (size % 3)
		ceiled_peak += 1;

	gap = 1;
	while (gap <= ceiled_peak)
		gap = gap * 3 + 1;

	return ((gap - 1) / 3);
}

/**
 * insertion_sort_gapped - Apply insertion sort on sublists of @array
 * using @gap value.
 *
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 * @gap: gap length.
 */
void insertion_sort_gapped(int *array, size_t size, size_t gap)
{
	size_t i, k, end_index;
	int j;

	end_index = size - gap;
	i = 0;
	while (i < end_index)
	{
		k = i + gap;
		while (k < size)
		{
			j = k - gap;
			while (j >= (int) i && array[j + gap] < array[j])
			{
				swap_int(array + j + gap, array + j);
				j -= gap;
			}
			k += gap;
		}
		i++;
	}
}

/**
 * insertion_sort - Apply insertion sort on  @array
 *
 * @array: The array to be sorted.
 * @size: Number of elements in @array.
 */
void insertion_sort(int *array, size_t size)
{
	size_t i;
	int j;

	i = 0;
	while (i < size)
	{
		j = i - 1;
		while (j >= 0 && array[j + 1] < array[j])
		{
			swap_int(array + j + 1, array + j);
			j--;
		}
		i++;
	}
}

/**
 * swap_int - swaps two integers.
 * @a: first integer address.
 * @b: second integer address.
 */
void swap_int(int *a, int *b)
{
	int temp;

	if (!a || !b)
		return;

	temp = *a;
	*a = *b;
	*b = temp;
}
