#include<stdio.h>
#define Max(a,b) (a>b?a:b)

int main() {
	int n, i;
	int max = 0;
	int arr[10000];
	int tmparr[10000];

	scanf("%d", &n);

	for (i = 1; i < n + 1; i++) {
		scanf("%d", &arr[i]);
	}
	tmparr[1] = arr[1];
	tmparr[2] = arr[1] + arr[2];
	tmparr[3] = Max(arr[1]+arr[2],Max(arr[1] + arr[3], arr[2] + arr[3]));

	if (n > 3) {
		for (i = 4; i < n + 1; i++) {
			max = Max(tmparr[i - 1], tmparr[i - 2] + arr[i]);
			tmparr[i] = Max(max, tmparr[i - 3] + arr[i - 1] + arr[i]);
			
		}
	}

	printf("%d", tmparr[n]);

	return 0;
}