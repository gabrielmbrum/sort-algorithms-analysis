#include <stdio.h>

/*
 * int parent(i) 
 * 	return i/2;
 *
 * int left(i)
 * 	return 2i;
 *
 * int right(i) 
 * 	return 2i + 1
 * 	
*/

void max_heapfy (heap *a, int i) {
	int l = left(i);
	int r = right(i);
	int maior = i;

	if (l <= a->size && a->array[l] > a->array[i])
		maior = l;

	if (r <= a->size && a->array[r] > a->array[maior])
		maior = r
	
	if (maior != i) {
		swap(&a->array[i], &a->array[maior]);
		max_heapfy(a, maior);
	}
}

void build_max_heap (heap *a) {
	a->size = a->lenght;
	for (int i = (a->lenght)/2; i>0; i--)
		max_heapfy(a, i);
}

void heapsort (int *a) {
	build_max_heap(a);
	for (int i = a->lenght; i > 1;  i--) {
		swap(&a->array[1], &a->array[i]);
		a->size--;
		max-heapfy(a, 1);
	}
}

