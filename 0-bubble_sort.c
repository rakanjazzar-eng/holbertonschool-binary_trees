#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t limit;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;

	limit = size;

	do {
		swapped = 0;

		for (i = 0; i + 1 < limit; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;

				print_array(array, size);
				swapped = 1;
			}
		}

		limit--;
	} while (swapped && limit > 1);
}
