#include<stdio.h>

int* Count_sort(int *arr, int arr_size) {
	int C[6] = { 0, };
	int *B;
	B = malloc(sizeof(int)*arr_size);
	int i;

	for (i = 1; i < arr_size; i++) {
		C[arr[i]]++;
	}

	for (i = 1; i < 6; i++) {
		C[i] = C[i - 1] + C[i];
	}

	for (i = arr_size-1; i > 0; i--) {
		B[C[arr[i]]] = arr[i];
		C[arr[i]]--;
	}

	return B;
}

int main(){
	int arr[11] = {0, 2, 0, 5, 3, 4, 4, 1, 2, 2, 5 };
	int *tmp;

	tmp = Count_sort(arr, 11);

	for (int i = 1; i < 11; i++) {
		printf("%d ", tmp[i]);
	}
	printf("\n ");

	

}