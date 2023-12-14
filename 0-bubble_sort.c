#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t swaps_count, i;
	int temp_swap;

	swaps_count = 1;
	while (swaps_count)
	{
		swaps_count = i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				swaps_count += 1;
				temp_swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp_swap;
				print_array(array, size);
			}
			i++;
		}
	}
}
