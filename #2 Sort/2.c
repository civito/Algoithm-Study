#include<stdio.h>

void BubbleSort(int *arr, int n) {
	int i, j, tmp;

	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main() {
	int arr[10] = { 1,14,3,8,5,12,16,4,25,2 };

	BubbleSort(arr, 10);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
	

}