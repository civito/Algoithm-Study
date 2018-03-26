#include<stdio.h>
int arr_size = 9;

void swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void Max_heapify(int *arr, int node) {
	int tmp;

	while (2 * node <= arr_size) {
		if (2 * node == arr_size) {
			if (arr[2 * node] > arr[node]) {
				swap(&arr[2 * node], &arr[node]);
			}
			break;
		}else{
			if (arr[2*node] > arr[2*node +1] && arr[2*node] > arr[node]) {
				swap(&arr[2 * node], &arr[node]);
				node = 2 * node;
			}
			else if (arr[2 * node] < arr[2 * node + 1] && arr[2 * node + 1] > arr[node]) {
				swap(&arr[2 * node + 1], &arr[node]);
				node = 2 * node + 1;
			}
			else break;
		}
	}
}

int Extract_Max(int *arr) {
	int max = arr[1];
	swap(&arr[arr_size--], &arr[1]);
	Max_heapify(arr, 1);
	return max;
}

int Insert_heap(int *arr, int num) {
	int i;
	arr[++arr_size] = num;
	i = arr_size;
	while (i > 1) {
		if (arr[i] > arr[i / 2]) {
			swap(&arr[i], &arr[i / 2]);
			i = i / 2;
		}
		else break;
	}
		
}

void Make_heap(int* arr) {
	for (int i = arr_size / 2; i > 0; i--) {
		Max_heapify(arr, i);
	}
}

int main() {
	int arr[10] = { 0, 2, 12, 3 ,15, 9, 4, 11, 8, 21 };
	Make_heap(arr);

	for (int i = 0; i <= arr_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("%d\n", Extract_Max(arr));
	Insert_heap(arr, 1);
	for (int i = 0; i <= arr_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("%d\n", Extract_Max(arr));
	for (int i = 0; i <= arr_size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

}