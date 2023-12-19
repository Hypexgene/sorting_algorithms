#include "sort.h"

/**
 * swap_integers - Swap two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap_integers(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}
/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the bubble sort algorithm.
 * @array: Pointer to the array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	do {
		swapped = false;
		for (i = 0; i < len - 1; i++) {
			if (array[i] > array[i + 1]) {
				swap_ints(&array[i], &array[i + 1]);
				print_array(array, size);
				swapped = true;
			}
		}
		len--;
	} while (swapped);
}
