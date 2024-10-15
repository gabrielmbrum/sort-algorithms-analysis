#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* countingsort(int arr[], int n, int k) {
    int *output, *count;
    output = (int*)malloc(sizeof(int) * n);
    count = (int*)calloc((k+1), sizeof(int)); // inicializa o array count com zeros

    // Conta a frequência de cada valor
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Modifica o array count para armazenar a posição de cada elemento
    for (int i = 1; i <= k; i++)
        count[i] += count[i - 1];

    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copia os elementos ordenados de volta para o array original
    return output;
}
