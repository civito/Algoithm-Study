#include<stdio.h>

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))   

int main() {
	int* dp;
	int N, i;

	scanf("%d", &N);

	dp = malloc(sizeof(int)*N+2);

	dp[1] = 0;
	dp[2] = 1;

	for (i = 3; i < N + 1; i++) {
		if (i % 2 == 0 && i % 6 != 0) {
			dp[i] = MIN(dp[i / 2], dp[i - 1]) + 1;
			printf(" 3 :%d\n", dp[3]);

			printf(" 4 :%d\n", dp[4]);

		}
		else if (i % 3 == 0 && i % 6 != 0) {
			dp[i] = MIN(dp[i / 3], dp[i - 1]) + 1;
		}
		else if (i % 6 == 0) {
			dp[i] = MIN(dp[i - 1], MIN(dp[i / 2], dp[i / 3])) + 1;
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}

	printf("%d", dp[N]);

}