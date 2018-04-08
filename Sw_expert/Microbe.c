#include<stdio.h>

#define X 0
#define Y 1
#define NUM 2
#define DIR 3

#define UP 1
#define RIGHT 4
#define LEFT 3
#define DOWN 2

int N, M, K;
int info[1000][4] = { 0, };
int cnt;


int main() {
	int testcase;
	int i, j, k;
	int sum;
	freopen("input.txt", "r", stdin);

	scanf("%d", &testcase);


	for (i = 0; i < testcase; i++) {
		cnt = 0;
		sum = 0;
		scanf("%d %d %d", &N, &M, &K);

		for (j = 0; j < K; j++) {
			scanf("%d %d %d %d", &info[j][Y], &info[j][X], &info[j][NUM], &info[j][DIR]);
		}

		while (cnt != M) {

			for (j = 0; j < K; j++) {
				if (info[j][NUM] > 0) {
					switch (info[j][DIR]) {
					case UP:
						info[j][Y] -= 1;
						if (info[j][Y] == 0) {
							info[j][NUM] /= 2;
							info[j][DIR] = DOWN;
						}
						break;
					case DOWN:
						info[j][Y] += 1;
						if (info[j][Y] == N - 1) {
							info[j][NUM] /= 2;
							info[j][DIR] = UP;
						}
						break;
					case RIGHT:
						info[j][X] += 1;
						if (info[j][X] == N - 1) {
							info[j][NUM] /= 2;
							info[j][DIR] = LEFT;
						}
						break;
					case LEFT:
						info[j][X] -= 1;
						if (info[j][X] == 0) {
							info[j][NUM] /= 2;
							info[j][DIR] = RIGHT;
						}
						break;
					}
				}
			}

			for (j = 0; j < K; j++) {
				for (k = 0; k < K; k++) {
					if (j != k && info[j][NUM] > 0 && info[k][NUM] > 0) {
						if (info[j][X] == info[k][X] && info[j][Y] == info[k][Y]) {
							if (info[k][NUM] > info[j][NUM]) {
								info[k][NUM] += info[j][NUM];
								info[j][NUM] = 0;
							}
						}
					}
				}
			}

			cnt++;
		}

		for (j = 0; j < K; j++) {
			sum += info[j][NUM];
		}

		printf("#%d %d\n", i + 1, sum);

	}

}