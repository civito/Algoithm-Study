#include<stdio.h>
int* V;
int N, S, M;
int DP[101][1000] = {0,};


int main() {
	int i, j;
	int flag = 0;

	scanf("%d %d %d", &N, &S, &M);

	V = (int *)malloc(sizeof(int)*N);

	for (i = 0; i < N; i++) {
		scanf("%d", &V[i]);
	}

	DP[0][S] = 1;

	for (i = 0; i < N; i++) {
		for (j = 0; j <= M; j++) {
			if (DP[i][j] == 0)
				continue;
			if (j - V[i] >= 0)
				DP[i + 1][j - V[i]] = 1;
			if (j + V[i] <= M)
				DP[i + 1][j + V[i]] = 1;
		}
	}

	for (i = M; i >= 0; i--) {
		if (DP[N][i] == 1){
			flag = 1;
			printf("%d", i);
			break;
		}
	}

	if (flag != 1)
		printf("-1\n");
	

}