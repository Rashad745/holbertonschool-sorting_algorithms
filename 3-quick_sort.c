#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
 * @a: pointer to first integer
 * @b: pointer to second integer
 * Return: void
 */
void swap_ints(int *a, int *b)
{
    int temp;

    if (a == b || *a == *b) /* do not swap identical elements */
        return;

    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: array size (for print_array)
 * Return: pivot index
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
            if (i != j)
            {
                swap_ints(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    if ((i + 1) != high)
    {
        swap_ints(&array[i + 1], &array[high]);
        print_array(array, size);
    }

    return (i + 1);
}

/**
 * quick_sort_recursive - recursive quicksort function
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: array size (for print_array)
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
 *              using the Quick sort algorithm (Lomuto)
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
