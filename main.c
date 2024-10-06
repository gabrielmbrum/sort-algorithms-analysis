#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "bubblesort.h"
#include "insertionsort.h"

int main () {
	clock_t  sorted_start, sorted_end, unsorted_start, unsorted_end, randomized_start, randomized_end;
	int n[6] = {10, 100, 1000, 10000, 100000, 1000000};
	int *sorted, *unsorted, *randomized, *aux;
	srand(time(NULL));
	/*
	for (int i = 0; i < 6; i++) {

		sorted = malloc(sizeof(int) * n[i]);
		unsorted = malloc(sizeof(int) * n[i]);
		randomized = malloc(sizeof(int) * n[i]);
		aux = malloc(sizeof(int) * n[i]);

		for (int j = 0; j < n[i]; j++) {
			sorted[j] = j;
			unsorted[j] = n[i]-j;
			randomized[j] = rand();
		}

		sorted_start = clock();
		for (int k = 0; k < 3; k++) {
			aux = bubblesort(sorted, n[i]);
		}
		sorted_end = clock();

		unsorted_start = clock();
		for (int k = 0; k < 3; k++) {
			aux = bubblesort(unsorted, n[i]);
		}
		unsorted_end = clock();
	
		randomized_start = clock();
		for (int k = 0; k < 3; k++) {
			aux = bubblesort(randomized, n[i]);
		}
		randomized_end = clock();	
		


		printf("\nwith n[i] = %d\nsorted: %fs\nunsorted: %fs\nrandomized: %fs\n",n[i], (double)(sorted_end - sorted_start)/(CLOCKS_PER_SEC*3), (double)(unsorted_end - unsorted_start)/(CLOCKS_PER_SEC*3) ,(double)(randomized_end - randomized_start)/(CLOCKS_PER_SEC*3));
	}
	*/
	for (int i = 0; i < 6; i++) {

		sorted = malloc(sizeof(int) * n[i]);
		unsorted = malloc(sizeof(int) * n[i]);
		randomized = malloc(sizeof(int) * n[i]);
		aux = malloc(sizeof(int) * n[i]);

		for (int j = 0; j < n[i]; j++) {
			sorted[j] = j;
			unsorted[j] = n[i]-j;
			randomized[j] = rand();
		}

		sorted_start = clock();
		for (int k = 0; k < 3; k++) {
			aux = insertionsort(sorted, n[i]);
		}
		sorted_end = clock();

		unsorted_start = clock();
		for (int k = 0; k < 3; k++) {
			aux = insertionsort(unsorted, n[i]);
		}
		unsorted_end = clock();
	
		randomized_start = clock();
		for (int k = 0; k < 3; k++) {
			aux = insertionsort(randomized, n[i]);
		}
		randomized_end = clock();	
		


		printf("\nwith n[i] = %d\nsorted: %fs\nunsorted: %fs\nrandomized: %fs\n",n[i], (double)(sorted_end - sorted_start)/(CLOCKS_PER_SEC*3), (double)(unsorted_end - unsorted_start)/(CLOCKS_PER_SEC*3) ,(double)(randomized_end - randomized_start)/(CLOCKS_PER_SEC*3));
	}
	return 0;
}
