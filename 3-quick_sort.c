cat > 3-quick_sort.c << 'EOF'
#include "sort.h"

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int lomuto_partition(int *array, int lo, int hi, size_t size)
{
    int pivot = array[hi];
    int i = lo - 1;
    int j;

    for (j = lo; j < hi; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }

    if (i + 1 != hi)
    {
        swap(&array[i + 1], &array[hi]);
        print_array(array, size);
    }

    return (i + 1);
}

void quick_sort_recursive(int *array, int lo, int hi, size_t size)
{
    int pivot_idx;

    if (lo < hi)
    {
        pivot_idx = lomuto_partition(array, lo, hi, size);
        quick_sort_recursive(array, lo, pivot_idx - 1, size);
        quick_sort_recursive(array, pivot_idx + 1, hi, size);
    }
}

void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_recursive(array, 0, (int)size - 1, size);
}
EOF
