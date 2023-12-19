#include "sort.h"

/**
 * swap_elements - Swaps two integers in an array.
 * @elem1: The first integer to swap.
 * @elem2: The second integer to swap.
 */
void swap_elements(int *elem1, int *elem2)
{
	int temp;

	temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *minimum;
	size_t i = 0, j;

	if (array == NULL || size < 2)
		return;

	while (i < size - 1)
	{
		minimum = array + i;
		j = i + 1;

		while (j < size)
		{
			minimum = (array[j] < *minimum) ? (array + j) : minimum;
			j++;
		}

		if ((array + i) != minimum)
		{
			swap_elements(array + i, minimum);
			print_array(array, size);
		}

		i++;
	}
}
