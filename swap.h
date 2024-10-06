#include <stdio.h>

void swap (int *a, int *b) {
	int x = *a;
	*a = *b;
	*b = x;
}
