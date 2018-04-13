#include<stdio.h>
#define DONG 1
#define SEO 2
#define NAM 4
#define BUK 3

int N, M, x, y, K;
int map[20][20];
int dice[6] = {0,};
int tmparr[6];

int command[1000] = { 0, };

void turn_dong() {
	int i;

	for (i = 0; i < 6; i++) {
		tmparr[i] = dice[i];
	}

	dice[3] = tmparr[0];
	dice[0] = tmparr[1];
	dice[5] = tmparr[3];
	dice[1] = tmparr[5];
}

void turn_seo() {
	int i;

	for (i = 0; i < 6; i++) {
		tmparr[i] = dice[i];
	}

	dice[1] = tmparr[0];
	dice[5] = tmparr[1];
	dice[3] = tmparr[5];
	dice[0] = tmparr[3];
}

void turn_nam() {
	int i;

	for (i = 0; i < 6; i++) {
		tmparr[i] = dice[i];
	}

	dice[0] = tmparr[4];
	dice[4] = tmparr[5];
	dice[5] = tmparr[2];
	dice[2] = tmparr[0];
}

void turn_buk() {
	int i;

	for (i = 0; i < 6; i++) {
		tmparr[i] = dice[i];
	}

	dice[4] = tmparr[0];
	dice[5] = tmparr[4];
	dice[2] = tmparr[5];
	dice[0] = tmparr[2];
}


int main() {
	int i, j;
	int cnt = 0;
	int flag;

	freopen("input.txt", "r", stdin);

	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);


	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (i = 0; i < K; i++) {
		scanf("%d", &command[i]);
	}

	//first
	dice[5] = map[y][x];

	while (cnt < K) {
		flag = 0;
		switch (command[cnt]) {
		case DONG :
			if (x == M - 1) {
				flag = 1;
			}else{
				turn_dong();
				if (map[y][++x] == 0) {
					map[y][x] = dice[5];
				}
				else {
					dice[5] = map[y][x];
					map[y][x] = 0;
				}
			}
			break;
		case SEO:
			if (x == 0) {
				flag = 1;
			}
			else {
				turn_seo();
				if (map[y][--x] == 0) {
					map[y][x] = dice[5];
				}
				else {
					dice[5] = map[y][x];
					map[y][x] = 0;
				}
			}
			break;
		case NAM:
			if (y == N-1) {
				flag = 1;
			}
			else {
				turn_nam();
				if (map[++y][x] == 0) {
					map[y][x] = dice[5];
				}
				else {
					dice[5] = map[y][x];
					map[y][x] = 0;
				}
			}
			break;
		case BUK:
			if (y == 0) {
				flag = 1;
			}
			else {
				turn_buk();
				if (map[--y][x] == 0) {
					map[y][x] = dice[5];
				}
				else {
					dice[5] = map[y][x];
					map[y][x] = 0;
				}
			}
			break;
		}
		if (flag == 0) {
			printf("%d\n", dice[0]);
		}
		cnt++;
	}
	
}