#include "sort.h"
#define leftChild(i) (2 * i + 1)
#define righttChild(i) (2 * i + 2)
#define Parent(i) ((i - 1) / 2)

void builtmaxheap(int *array, size_t n)
{
	size_t root, child;
	size_t start = n / 2, end = n;

	while (end > 1)
	{
		if (start > 0)
			start--;
		else
		{
			end--;
			swap_int(&array[end], &array[0]);
			print_array(array, n);
		}

		root = start;
		while (leftChild(root) < end)
		{
			child = leftChild(root);
			if ((child + 1 < end) && (array[child] < array[child + 1]))
				child++;

			if (array[root] < array[child])
			{
				swap_int(&array[root], & array[child]);
				print_array(array, n);
				root = child;
			}
			else
				break;
		}
	}
}

void heap_sort(int *array, size_t size)
{
	if (array && size > 1)
		builtmaxheap(array, size);
}

/**
 * swap_int - This function swaps two integers
 * @a: The first integer
 * @b: The second integer
 */

void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
