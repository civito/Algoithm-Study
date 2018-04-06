#include<stdio.h>
int check[16] = { 0, };
int S[16][16] = { 0, };

int min;
int N;

int cal(int num) {
	int sum = 0;
	int i, j;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (check[i] == num && check[j] == num)
				sum += S[i][j];

		}
	}
	return sum;
}


void DFS(int k, int cnt) {
	int i;
	int val;

	if(cnt == N / 2){
		val = abs(cal(1) - cal(0));
		if (val < min)
			min = val;
		/*for (i = 0; i < 6; i++) {
			if(check[i] == 1){
				printf("%d ", i);
			}
		}
		printf("\n");*/
		return;
	}

	for (i = k; i < N; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			DFS(i ,cnt + 1);
			check[i] = 0;
		}
	}
}


int main() {
	int testcase;
	int i, j, k;
	freopen("input.txt", "r", stdin);

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		min = 1000;
		scanf("%d", &N);

		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				scanf("%d", &S[j][k]);
			}
		}

		check[0] = 1;
		DFS(0, 1);

		printf("#%d %d\n", i + 1, min);
	}
}