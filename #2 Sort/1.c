#include<stdio.h>

void SelecetionSort(int *arr, int n) {
	int i, j, tmp;
	int idx;

	for (i = n - 1; i > 0; i--) {
		int max = -1;
		for (j = 0; j <= i; j++) {
			if (arr[j] > max) {
				max = arr[j];
				idx = j;
			}
		}
		tmp = arr[i];
		arr[i] = max;
		arr[idx] = tmp;
	}
}


int main() {
	int arr[10] = { 1,14,3,8,5,12,16,4,25,2 };

	SelecetionSort(arr, 10);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
	

}