#include "sort.h"

/**
 * lomuto_sort - Implements the quicksort algorithm using recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The lower index of the array portion to order.
 * @high: The higher index of the array portion to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
        int partition;

        if (low < high)
        {
                partition = lomuto_partition(array, size, low, high);
                lomuto_sort(array, size, low, partition - 1);
                lomuto_sort(array, size, partition + 1, high);
        }
}

/**
 * swap_elements - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_elements(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
        if (array == NULL || size < 2)
                return;

        lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_partition - Orders a portion of an array of integers using
 *                    the Lomuto partition scheme with the last element as the pivot.
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The lower index of the portion to order.
 * @high: The higher index of the portion to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot, i, j;

	pivot = array + high;
	i = low - 1;

	while (1)
	{
		for (j = low; j <= high - 1 && array[j] < *pivot; j++)
			;

		for (; j <= high - 1 && array[j] > *pivot; j++)
			;

		if (j >= high)
			break;

		swap_elements(array + i + 1, array + j);
		print_array(array, size);
		i++;
	}

	swap_elements(array + i + 1, pivot);
	print_array(array, size);

	return i + 1;
}
