#include <stdio.h>
#include "swap.h"

int* bubblesort (int *a, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-1-i; j++) {
			if (a[j] > a[j+1])
				swap(&a[j], &a[j+1]);
		}
	}

	return a;
}
