#include<stdio.h>

int main() {
	int num[1001];
	int prio[1001] = { 0 , };
	int i,j, testcase;
	int n;
	int pivot;
	int max;

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {

		scanf("%d", &n);

		for (j = 0; j < n; j++) {
			scanf("%d", &num[j]);
		}

		prio[0] = 0;
		pivot = 1;

		while (pivot != n) {
			max = -1;
			for (j = pivot - 1; j >= 0; j--) {
				if (num[j] < num[pivot] && max < prio[j]) {
					max = prio[j];
				}
			}
			prio[pivot] = max + 1;
			pivot++;
		}
		for (j = 0; j < n; j++) {
		}

		max = 0;
		for (j = 0; j < n; j++) {
			if (prio[j] > max)
				max = prio[j];
		}

		printf("#%d %d\n",i+1, max + 1);
	}
}