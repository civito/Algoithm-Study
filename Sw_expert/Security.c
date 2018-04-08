#include<stdio.h>
#include<stdlib.h>

int S[20][20];
int N, M;
int K;
int max;

int pos(int y, int x) {
	if (x < 0 || y < 0 || x >= N || y >= N)
		return 0;

	if (S[y][x] == 1)
		return 1;
	else
		return 0;


}


void how_many(int y, int x) {
	int sum, i, j;

	sum = 0;

	for (i = y - K + 1; i <= y + K - 1; i++) {
		for (j = x - K + 1; j <= x + K - 1; j++){
			if (abs(i - y) + abs(j - x) <= K - 1) {
				sum += pos(i, j);
				if ((sum * M) - (K*K) - (K - 1)*(K - 1) > 0){
					//printf("k = %d, [%d][%d] [%d][%d] sum = %d, max = %d\n", K, y, x, i, j, sum, max);
					if (max < sum){
						max = sum;
					}
				}
			}
		}
	}
}


int main() {
	int testcase;
	int i, j, k;
	freopen("input.txt", "r", stdin);

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		scanf("%d %d", &N, &M);

		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				scanf("%d", &S[j][k]);
			}
		}
		max = 0;
		K = 1;
		while (K <= N+1) {		
			for (j = 0; j < N; j++) {
				for (k = 0; k < N; k++) {
					how_many(j, k);
				}
			}
			K++;
		}
		printf("#%d %d\n", i + 1, max);
	}
}