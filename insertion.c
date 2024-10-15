#include <stdio.h>

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
