#ifndef SORT_H
#define SORT_H

/* Libraries */
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Utility Functions prototypes */
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void swap_int(int *a, int *b);


/* Main Functions prototypes */
void bubble_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);

/* Utility Functions for Shell Sort */
size_t initial_knuth_gap(size_t size);
void insertion_sort_gapped(int *array, size_t size, size_t gap);
void insertion_sort(int *array, size_t size);

#endif /* SORT_H */
