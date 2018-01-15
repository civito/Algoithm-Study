#include<stdio.h>
#define MAX(a,b) a>b?a:b

int FindMax(int *arr, int begin, int end) {
	if (begin == end)
		return arr[begin];
	else
		return MAX(arr[begin], FindMax(arr, begin + 1, end));
}

int main() {
	int arr[10] = { 1,5,6,9,10,3,17,15, 4, 2 };

	printf("%d", FindMax(arr, 0, 9));
}