#include <stdio.h>
#include <stdlib.h>

int *shellSort (int *vet, int size);

int *bucketSort(int *vet, int size) {
    typedef struct {
        int *pos;      
        int topo;
        int capacidade;  
    } Bucket;

    
    int num_buckets = 100;
    Bucket *balde = malloc(num_buckets * sizeof(Bucket));
    if (balde == NULL) {
        printf("Erro de alocação de memória para os baldes\n");
        exit(1);
    }

    
    for (int i = 0; i < num_buckets; i++) {
        balde[i].topo = 0;
        balde[i].capacidade = size / num_buckets + 1; 
        balde[i].pos = malloc(balde[i].capacidade * sizeof(int));
        if (balde[i].pos == NULL) {
            printf("Erro de alocação de memória para o balde\n");
            exit(1);
        }
    }

    
    int min_value = vet[0];
    int max_value = vet[0];
    for (int i = 1; i < size; i++) {
        if (vet[i] < min_value) min_value = vet[i];
        if (vet[i] > max_value) max_value = vet[i];
    }

    
    for (int i = 0; i < size; i++) {
        
        int index = (vet[i] - min_value) * (num_buckets - 1) / (max_value - min_value);
        if (index < 0) index = 0;
        if (index >= num_buckets) index = num_buckets - 1;  

        
        if (balde[index].topo == balde[index].capacidade) {
            
            balde[index].capacidade *= 2;
            balde[index].pos = realloc(balde[index].pos, balde[index].capacidade * sizeof(int));
            if (balde[index].pos == NULL) {
                printf("Erro ao realocar memória para o balde\n");
                exit(1);
            }
        }

        
        balde[index].pos[balde[index].topo] = vet[i];
        balde[index].topo++;
    }

    int k = 0;
    
    for (int i = 0; i < num_buckets; i++) {
        if (balde[i].topo > 0) {
            shellSort(balde[i].pos, balde[i].topo);

            
            for (int j = 0; j < balde[i].topo; j++) {
                vet[k] = balde[i].pos[j];
                k++;
            }
        }
        free(balde[i].pos);
    }

    
    free(balde);

    return vet;
}

int *shellSort (int *vet, int size) {
    int i, j, value;
 
    int h = 1;

    while(h < size)
        h = 3*h+1;

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