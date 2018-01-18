#include<stdio.h>

void InsertionSort(int *arr, int n) {
	int i, j, key, tmp;

	for (i = 1; i <= n - 1; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}

}

int main() {
	int arr[10] = { 1,14,-1,8,5,12,16,4,25,2 };

	InsertionSort(arr, 10);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
	

}