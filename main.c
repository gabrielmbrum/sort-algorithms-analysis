#include <time.h>
#include <stdio.h>
#include <stdlib.h>

/*------------------ auxiliar functions ---------------------------*/
int getMax(int vet[], int n) { //used on the counting sort, it's necessary the maximum value of the array
    int mx = vet[0];
    for (int i = 1; i < n; i++) {
        if (vet[i] > mx) {
            mx = vet[i];
        }
    }
    return mx;
}

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*------------------------ quick sort ---------------------------*/
int partition(int *a, int left, int right) {
    int pivot = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        
        while (a[i] < pivot) {
            i++;
        }
        
        while (a[j] > pivot) {
            j--;
        }
        
        if (i <= j) {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    return i;
}

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

/*------------------------ selection sort ------------------------*/
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

/*--------------------------- bubble sort------------------------*/
int* bubblesort (int *a, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-1-i; j++) {
			if (a[j] > a[j+1])
				swap(&a[j], &a[j+1]);
			else
				break;
		}
	}

	return a;
}

/*------------------------- insertion sort ---------------------*/
int* insertionsort (int *a, int n) {
	int i, j, k, x;
	for (i = 1; i<n; i++) {
		for (j = i; j>0; j--) {
			if (a[j-1] < a[i])
				break;
		}
		x = a[i];
		for (k = i; k > j; k--)
			a[k] = a[k-1];

		a[j] = x;
	}

	return a;
}

/*----------------------- couting sort -------------------------*/
int* countingsort(int arr[], int n, int k) {
    int *output, *count;
    output = (int*)malloc(sizeof(int) * n);
    count = (int*)calloc((k+1), sizeof(int)); 

    
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    
    for (int i = 1; i <= k; i++)
        count[i] += count[i - 1];

    
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    free(count);
    return output;
}

/*----------------------- merge sort --------------------------*/
int *mergeSort(int *vet, int inicio, int fim) { 
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;
        mergeSort (vet, inicio, meio);  
        mergeSort (vet, meio+1, fim);

        int *esquerda = malloc((meio-inicio+1)*(sizeof(int)));
        int *direita = malloc((fim-meio)*(sizeof(int)));
    
        for(int i=0;i<meio-inicio+1;i++)
            esquerda[i] = vet[inicio+i];
      
        for(int i=0;i<fim-meio;i++)
            direita[i] = vet[meio+1+i];

        int i=0;
        int j=0;
        int k = inicio;

        while ( i < meio-inicio + 1 && j < fim-meio){
            if(esquerda[i] <= direita[j]){
                vet[k] = esquerda[i];
                i++;
            } else {
                vet[k] = direita[j];
                j++;
            }
            k++;
        }

        while (i < meio-inicio + 1) {
            vet[k] = esquerda[i];
            i++;
            k++;
        }

        while (j < fim-meio) {
            vet[k] = direita[j];
            j++;
            k++;
        }

        free(esquerda);
        free(direita);
        return vet;
    }
}

/*------------------------- shell sort ------------------------*/
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

/*------------------- radix sort -----------------------*/
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

/*-------------------------- heap sort ----------------------*/
typedef struct {
    int *array;  
    int size;      
    int length; 
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

/*-------------------------- bucket sort -------------------------*/
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

int main () {
    //variables used to calculate the time spend into each array kind
    //sorted = in asc order || unsorted = in desc order || randomized = random order
	clock_t  sorted_start, sorted_end, unsorted_start, unsorted_end, randomized_start, randomized_end;
	
    //array with the size of each iteration
    int n[6] = {10, 100, 1000, 10000, 100000, 1000000};
        
    //array used to realize the tests
    int *sorted, *unsorted, *randomized, *aux;

	srand(time(NULL));
	
	for (int i = 0; i < 6; i++) {

		sorted = malloc(sizeof(int) * n[i]);
		unsorted = malloc(sizeof(int) * n[i]);
		randomized = malloc(sizeof(int) * n[i]);
		aux = malloc(sizeof(int) * n[i]);

        //fill the arrays with the respectives kinds of numbers (in order, desc order and random)
		for (int j = 0; j < n[i]; j++) {
			sorted[j] = j;
			unsorted[j] = n[i]-j;
			randomized[j] = rand() % n[i];
		}

        //in order test
		sorted_start = clock();
		for (int k = 0; k < 3; k++) {
			aux = bucketSort(sorted, n[i]);
		}
		sorted_end = clock();

        //in desc order test
		unsorted_start = clock();
		for (int k = 0; k < 3; k++) {
			aux = bucketSort(unsorted, n[i]);
		}
		unsorted_end = clock();
	
        //random test
		randomized_start = clock();
		for (int k = 0; k < 3; k++) {
			aux = bucketSort(randomized, n[i]);
		}
		randomized_end = clock();	

        //print the times spend in each kind of array
		printf("\nwith n[i] = %d\nsorted: %fs\nunsorted: %fs\nrandomized: %fs\n",n[i], (double)(sorted_end - sorted_start)/(CLOCKS_PER_SEC*3), (double)(unsorted_end - unsorted_start)/(CLOCKS_PER_SEC*3) ,(double)(randomized_end - randomized_start)/(CLOCKS_PER_SEC*3));
	}

	return 0;
}

/*
    for heap sort, we used this for loop, it's a little different for the reason of heap struct

	for (int i = 0; i < 6; i++) {

		sorted.array = malloc(sizeof(int) * n[i]);
		unsorted.array = malloc(sizeof(int) * n[i]);
		randomized.array = malloc(sizeof(int) * n[i]);
		aux.array = malloc(sizeof(int) * n[i]);

		sorted.length = unsorted.length = randomized.length = n[i];
		sorted.size = unsorted.size = randomized.size = randomized.size;

		for (int j = 0; j < n[i]; j++) {
			sorted.array[j] = j;
			unsorted.array[j] = n[i]-j;
			randomized.array[j] = rand();
		}

		aux = sorted;
		sorted_start = clock();
		for (int k = 0; k < 3; k++) {
			heapsort(&aux);
			aux = sorted;
		}
		sorted_end = clock();

		aux = unsorted;
		unsorted_start = clock();
		for (int k = 0; k < 3; k++) {
			heapsort(&aux);
			aux = unsorted;

		}
		unsorted_end = clock();
	
		aux = randomized;
		randomized_start = clock();
		for (int k = 0; k < 3; k++) {
			heapsort(&aux);
			aux = randomized;
		}
		randomized_end = clock();	

		printf("\nwith n[i] = %d\nsorted: %fs\nunsorted: %fs\nrandomized: %fs\n",n[i], (double)(sorted_end - sorted_start)/(CLOCKS_PER_SEC*3), (double)(unsorted_end - unsorted_start)/(CLOCKS_PER_SEC*3) ,(double)(randomized_end - randomized_start)/(CLOCKS_PER_SEC*3));
	}

	*/