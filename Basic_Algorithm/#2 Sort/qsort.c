#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b) {
	return *(int*)b - *(int*)a;
}

int main() {
	int arr[10] = { 10, 4, 6, 2, 19, 23, 3 , 12, 9, 33 };

	qsort(arr, sizeof(arr) / sizeof(int), sizeof(int), compare);

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}