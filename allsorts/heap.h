typedef struct {
    int *array;  // Ponteiro para o array de inteiros
    int size;    // Tamanho atual do heap
    int length;  // Comprimento total do array
} heap;

int parent(int i);

int left(int i);

int right(int i);

void max_heapfy (heap *a, int i);

void build_max_heap (heap *a);

void heapsort (heap *a);