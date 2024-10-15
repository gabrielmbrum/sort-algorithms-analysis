#include <stdio.h>
#include "ordena.h"

int *shellSort(int *vet, int size) {
    int i, j, value;
 
    int h = 1;
    while(h < size) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < size; i++) {
            value = vet[i];
            j = i;
            while (j > h-1 && value <= vet[j - h]) {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = value;
        }
        h = h/3;
    }
    return vet;
}