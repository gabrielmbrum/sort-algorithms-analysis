#include "swap.h"

typedef struct {
    int *array;  // Ponteiro para o array de inteiros
    int size;    // Tamanho atual do heap
    int length;  // Comprimento total do array
} heap;

int parent(int i) {
 	return (i/2);
}

int left(int i) {
 	return 2*i;
}

int right(int i) { 
	return (2*i + 1);
}

void max_heapfy (heap *a, int i) {
	int l = left(i);
	int r = right(i);
	int maior = i;

	if (l <= a->size && a->array[l] > a->array[i])
		maior = l;

	if (r <= a->size && a->array[r] > a->array[maior])
		maior = r;
	
	if (maior != i) {
		swap(&a->array[i], &a->array[maior]);
		max_heapfy(a, maior);
	}
}

void build_max_heap (heap *a) {
	a->size = a->length;
	for (int i = (a->length)/2; i>=1; i--)
		max_heapfy(a, i);
}

void heapsort (heap *a) {
	build_max_heap(a);
	for (int i = a->length; i > 1;  i--) {
		swap(&a->array[1], &a->array[i]);
		a->size--;
		max_heapfy(a, 1);
	}
}

