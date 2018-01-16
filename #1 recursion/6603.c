#include<stdio.h>

#define TRUE 1
#define FALSE 0

int include[100] = { 0, };
int *arr;

int lotto(int k, int cnt, int n) {
	
	if (k == n && cnt < 6) return -1;
	if (cnt == 6) {
		for (int i = 0; i < n; i++) {
			if (include[i] == TRUE) {
				printf("%d ", arr[i]);
			}
		}
		printf("\n");
	}
	else {
		include[k] = FALSE;
		lotto(k + 1, cnt, n);
		include[k] = TRUE;
		lotto(k + 1, cnt+1, n);
	}

}

int main() {
	int n;
	int i;

	scanf("%d", &n);

	arr = (int *)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	lotto(0, 0, n);

}
