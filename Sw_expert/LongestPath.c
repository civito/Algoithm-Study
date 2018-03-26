#include<stdio.h>
#define BLACK 1
#define WHITE 0

int Connect[11][11] = {0,};
int Color[11] = {0,};
int max;
int N, M;

void longest(int x, int cnt) {
	int i;

	if (cnt > max)
		max = cnt;

	for (i = 1; i <= N; i++) {
		if (Connect[x][i] == 1 && Color[i] == WHITE) {
			Color[i] = BLACK;
			longest(i, cnt + 1);
			Color[i] = WHITE;
		}
	}
	return;
}

int main() {
	int testcase;
	int from, to;
	int i, j, k;

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {

		scanf("%d %d", &N, &M);

		for (j = 0; j < M; j++) {
			scanf("%d %d", &from, &to);
			Connect[from][to] = 1;
			Connect[to][from] = 1;
		}

		max = 0;

		for (j = 1; j <= N; j++) {
			Color[j] = BLACK;
			longest(j, 1);
			Color[j] = WHITE;
		}
		
		for (j = 1; j <= N; j++) {
			for (k = 1; k <= N; k++) {
				Connect[k][j] = 0;
			}
		}

		printf("%d", max);



	}



}