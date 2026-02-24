#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Print array helper */
void print_array(const int *array, size_t size);

/* Sorting function prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(int **list); /* for doubly linked list */
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size); /* <<< Add this line */

/* Swap helper (optional if used externally) */
void swap_ints(int *a, int *b);

#endif /* SORT_H */
