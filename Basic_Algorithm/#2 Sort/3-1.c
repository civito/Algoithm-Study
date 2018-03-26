#include<stdio.h>

void InsertionSort(int *arr, int n) {
	int i, j, k, tmp;

	for (i = 1; i <= n - 1; i++) {
		for (j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j]) {
				tmp = arr[i];
				for (k = i - 1; k >= j+1; k--) {
					arr[k + 1] = arr[k];
				}
				arr[j+1] = tmp;
				break;
			}
			if (j == 0) {
				tmp = arr[i];
				for (k = i - 1; k >= 0; k--) {
					arr[k + 1] = arr[k];
				}
				arr[0] = tmp;
			}
		}	
	}

}

int main() {
	int arr[10] = { 1,14,-1,8,5,12,16,4,25,2 };

	InsertionSort(arr, 10);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
	

}