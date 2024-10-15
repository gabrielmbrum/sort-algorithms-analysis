#include "ordena.h"
#include <stdio.h>
#include <stdlib.h>


int getMax(int vet[], int n) {
    int mx = vet[0];
    for (int i = 1; i < n; i++) {
        if (vet[i] > mx) {
            mx = vet[i];
        }
    }
    return mx;
}

void countSort(int *vet, int size, int exp) {
    int *output = (int *)malloc(size * sizeof(int)); 
    int count[10] = {0}; 

    for (int i = 0; i < size; i++) {
        count[(vet[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(vet[i] / exp) % 10] - 1] = vet[i];
        count[(vet[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        vet[i] = output[i];
    }

    free(output);
}

int *radixSort(int *vet, int size) {
    int m = getMax(vet, size);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(vet, size, exp);
    }
    return vet;
}

