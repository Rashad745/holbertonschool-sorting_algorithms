#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
 * Prints the array only if a real swap occurs
 * @a: first integer
 * @b: second integer
 * @array: array being sorted
 * @size: size of the array
 */
void swap_ints(int *a, int *b, int *array, size_t size)
{
    int temp;

    if (*a == *b) /* skip swapping identical values */
        return;

    temp = *a;
    *a = *b;
    *b = temp;

    print_array(array, size);
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index (pivot)
 * @size: size of the array
 * Return: index of the pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap_ints(&array[i], &array[j], array, size);
        }
    }

    swap_ints(&array[i + 1], &array[high], array, size);

    return (i + 1);
}

/**
 * quick_sort_recursive - recursive quicksort
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int pivot_index;

    if (low < high)
    {
        pivot_index = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, pivot_index - 1, size);
        quick_sort_recursive(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
