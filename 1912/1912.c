#include<stdio.h>

int main() {
	int n, i;
	int arr[100010] = {0};
	int f[100010] = {0};
	int max = 0;


	scanf("%d", &n);


	for (i = 1; i < n+1; i++) {
		scanf("%d", &arr[i]);
	}

	for (i = 1; i < n + 1; i++) {
		if (f[i - 1] + arr[i] > arr[i]) {
			f[i] = f[i-1] + arr[i];
			
		}
		else
			f[i] = arr[i];
	}

	for (i = 1; i < n + 1; i++) {
		if (max < f[i]) max = f[i];
	}

	printf("%d\n", max);
}

