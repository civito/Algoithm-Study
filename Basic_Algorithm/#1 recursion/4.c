#include<stdio.h>

int SumArr(int* arr, int n) {
	if (n == 0)
		return 0;
	else
		return arr[n - 1] + SumArr(arr, n - 1);
}

int main() {
	int arr[5] = { 1,2,3,4,5 };
	
	printf("%d",SumArr(arr,sizeof(arr)/sizeof(int)));
}
