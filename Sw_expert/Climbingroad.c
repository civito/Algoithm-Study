#include<stdio.h>
int N, K;
int S[8][8];
int check[8][8] = { 0, };
int MAX;
int cnt;

int find_max() {
	int i, j;
	int max = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (max < S[i][j]) {
				max = S[i][j];
			}
		}
	}
	return max;
}


void DFS(int x, int y) {
	/*for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			printf("%d", check[a][b]);
		}
		printf("\n");
	}
	printf("\n");
	*/
	if (y - 1 >= 0 && S[y - 1][x] < S[y][x] && check[y - 1][x] == 0) {
		check[y - 1][x] = 1;
		cnt++;
		DFS(x, y - 1);
		cnt--;
		check[y - 1][x] = 0;
	}

	if (y + 1 < N && S[y + 1][x] < S[y][x] && check[y + 1][x] == 0) {
		check[y + 1][x] = 1;
		cnt++;
		DFS(x, y + 1);
		cnt--;
		check[y + 1][x] = 0;
	}

	if (x + 1 < N && S[y][x+1] < S[y][x] && check[y][x+1] == 0) {
		check[y][x+1] = 1;
		cnt++;
		DFS(x+1, y);
		cnt--;
		check[y][x+1] = 0;
	}

	if (x - 1 >= 0 && S[y][x - 1] < S[y][x] && check[y][x - 1] == 0) {
		check[y][x - 1] = 1;
		cnt++;
		DFS(x - 1, y);
		cnt--;
		check[y][x - 1] = 0;
	}

	if (MAX < cnt){
		MAX = cnt;
	}

	return;
}


int main() {
	int testcase;
	int i, j, k, q, w, r,a,b;
	int max;
	freopen("input.txt", "r", stdin);

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		MAX = 0;
		max = 0;
		scanf("%d %d", &N, &K);

		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				scanf("%d", &S[j][k]);
			}
		}

		max = find_max();

		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				if (S[j][k] == max) {
					cnt = 0;
					check[j][k] = 1;
					cnt++;
					DFS(k, j);
					check[j][k] = 0;

					for (q = 0; q < N; q++) {
						for (w = 0; w < N; w++) {
							r = 1;
							while (r <= K) {
								S[q][w] -= r;
								cnt = 0;
								check[j][k] = 1;
								cnt++;
								//printf("S[%d][%d]", j, k);
								//printf("[%d][%d] r = %d\n", q, w, r);
								DFS(k ,j);
								check[j][k] = 0;
								S[q][w] += r;
								r++;
								
							}
						}
					}
				}
			}
		}

		printf("#%d %d\n", i + 1, MAX);
	}
}