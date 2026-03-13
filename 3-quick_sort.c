k#include "sort.h"

/**
 * swap_ints - Massivdəki iki tam ədədin yerini dəyişir.
 * @array: Ümumi massiv (çap üçün lazımdır).
 * @size: Massivin ölçüsü.
 * @a: Birinci ədədin ünvanı.
 * @b: İkinci ədədin ünvanı.
 */
void swap_ints(int *array, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;

		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto_partition - Lomuto sxemi ilə massivi bölür.
 * @array: Bölünəcək massiv.
 * @size: Massivin ölçüsü.
 * @left: Alt-massivin başlanğıc indeksi.
 * @right: Alt-massivin son indeksi (pivot buradadır).
 *
 * Return: Pivotun sonuncu indeksini qaytarır.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot = array + right;
	int i, j;

	for (i = j = left; j < right; j++)
	{
		if (array[j] < *pivot)
		{
			swap_ints(array, size, array + i, array + j);
			i++;
		}
	}

	swap_ints(array, size, array + i, pivot);

	return (i);
}

/**
 * lomuto_sort - Rekursiv olaraq Quick Sort tətbiq edir.
 * @array: Massiv.
 * @size: Massivin tam ölçüsü.
 * @left: Alt-massivin sol sərhədi.
 * @right: Alt-massivin sağ sərhədi.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Quick Sort alqoritmi ilə massivi sıralayır.
 * @array: Sıralanacaq massiv.
 * @size: Massivin ölçüsü.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
