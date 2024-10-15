int *selectionSort(int *vet, int size) {
    for (int i = size-1; i >=0; i--) {
        int maior = i;
        for (int j = 0; j < i; j++) {
            if (vet[j] > vet[maior]) {
                maior = j; // Atualiza o maior se necessário
            }
        }

        // Troca os elementos
        if (maior != i) { // Verifica se é necessário trocar
            int aux = vet[i];
            vet[i] = vet[maior];
            vet[maior] = aux;
        }
    }
    return vet;
}