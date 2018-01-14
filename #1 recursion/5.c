#include<stdio.h>

int BinarySearch(int *arr, int begin, int end, int num) {
	int middle;

	if (begin > end)
		return -1;
	else {
		middle = (begin + end) / 2;
		if (num == arr[middle])
			return middle;
		else if (num > arr[middle])
			return BinarySearch(arr, middle + 1, end, num);
		else
			return BinarySearch(arr, begin, middle - 1, num);
	}
}

int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int num;

	scanf("%d", &num);

	printf("%d", BinarySearch(arr, 0, 9, num));
}