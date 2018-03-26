#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b) {
	return *(int*)b - *(int*)a;
}

int main() {
	int arr[100000] = { 0, };
	int testcase;
	int i, j, sum;
	int num;
	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		scanf("%d", &num);

		sum = 0;
		for (j = 0; j < num; j++) {
			scanf("%d", &arr[j]);
			sum += arr[j];
		}

		qsort(arr, num, sizeof(int), compare);

		for (j = 1; j <= num / 3; j++) {
			sum -= arr[3 * j - 1];
		}

		printf("#%d %d",i+1, sum);
	}

	

}