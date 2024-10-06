#include <stdio.h>
#include "swap.h"

int partition(int *a, int left, int right) {
    int pivot = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        // Encontra o primeiro elemento à esquerda que é maior que o pivô
        while (a[i] < pivot) {
            i++;
        }
        // Encontra o primeiro elemento à direita que é menor que o pivô
        while (a[j] > pivot) {
            j--;
        }
        // Troca os elementos encontrados fora de lugar
        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    return i;
}

// Função QuickSort recursiva
void quick(int *a, int left, int right) {
    if (left < right) {
        int index = partition(a, left, right);
	quick(a, left, index - 1);
        quick(a, index, right);
    }
}

int *quicksort(int *a, int n) {
    quick(a, 0, n - 1);
    return a;
}

