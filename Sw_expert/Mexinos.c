#include<stdio.h>
#define X 0
#define Y 1

int core;
int max_core;
int min_length;
int N;
int S[12][12];
int mem[12][2] = {0,};

int cal_length() {
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (S[i][j] == 3)
				num += 1;
		}
	}
	return num;
}


int up_color(int x, int y) {
	if (S[y][x] != 0)
		return -1;

	if (S[y][x] == 0 && y == 0)
		return 1;

	return up_color(x, y - 1);
}

int down_color(int x, int y) {
	if (S[y][x] != 0)
		return -1;

	if (S[y][x] == 0 && y == N-1)
		return 1;

	return down_color(x, y + 1);
}
int right_color(int x, int y) {
	if (S[y][x] != 0)
		return -1;

	if (S[y][x] == 0 && x == N-1)
		return 1;

	return right_color(x + 1, y);
}
int left_color(int x, int y) {
	if (S[y][x] != 0)
		return -1;

	if (S[y][x] == 0 && x == 0)
		return 1;

	return left_color(x - 1, y);
}

void color_up(int x, int y, int num) {
	for (int i = 0; i < y; i++) {
		S[i][x] = num;
	}
}

void color_down(int x, int y, int num) {
	for (int i = y+1; i < N; i++) {
		S[i][x] = num;
	}
}

void color_right(int x, int y, int num) {
	for (int i = x+1; i < N; i++) {
		S[y][i] = num;
	}
}

void color_left(int x, int y, int num) {
	for (int i = 0; i < x; i++) {
		S[y][i] = num;
	}
}

void DFS(int n, int cnt, int x ,int y) {
	int length;
	int i, j;

	if (n == core) {
		printf("cnt = %d\n", cnt);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				printf("%d", S[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		if (cnt > max_core) {
			max_core = cnt;
			min_length = cal_length();
			/*
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					printf("%d", S[i][j]);
				}
				printf("\n");
			}*/
			//printf("%d\n", cnt);
		}
		else if (cnt == max_core) {
			length = cal_length();
			if (min_length > length) {
				min_length = length;
				/*for (i = 0; i < N; i++) {
					for (j = 0; j < N; j++) {
						printf("%d", S[i][j]);
					}
					printf("\n");
				}
				printf("\n");*/
			}
		}
		else;
		return;
	}


	if (up_color(x, y - 1) == 1) {
			color_up(x, y, 3);
			S[y][x] = 2;
			DFS(n + 1, cnt + 1, mem[n+1][X],mem[n+1][Y]);
			S[y][x] = 1;
			color_up(x, y, 0);
	}
	if (down_color(x, y+1) == 1) {
			color_down(x, y, 3);
			S[y][x] = 2;
			DFS(n + 1, cnt + 1, mem[n + 1][X], mem[n + 1][Y]);
			S[y][x] = 1;
			color_down(x, y, 0);
	}

	if (left_color(x-1, y) == 1) {
			color_left(x, y, 3);
			S[y][x] = 2;
			DFS(n + 1, cnt + 1, mem[n + 1][X], mem[n + 1][Y]);
			S[y][x] = 1;
			color_left(x, y, 0);
	}
	
	if (right_color(x+1, y) == 1) {
			color_right(x, y, 3);
			S[y][x] = 2;
			DFS(n + 1, cnt + 1, mem[n + 1][X], mem[n + 1][Y]);
			S[y][x] = 1;
			color_right(x, y, 0);
	}

	S[y][x] = 2;
	DFS(n + 1, cnt, mem[n + 1][X], mem[n + 1][Y]);
	S[y][x] = 1;
}


int main() {
	int testcase;
	int i, j, k;

	freopen("input.txt", "r", stdin);
	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		core = 0;
		max_core = 0;
		min_length = 1000;
		scanf("%d", &N);

		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				scanf("%d", &S[j][k]);
				if (S[j][k] == 1) {
					if (j == 0 || k == 0 || j == N - 1 || k == N - 1) {
						S[j][k] = 2;
					}
					else {
						mem[core][X] = k;
						mem[core][Y] = j;
						core++;
					}
					printf("%d\n", core);
				}				
			}
		}
		DFS(0,0,mem[0][X], mem[0][Y]);
		printf("#%d %d\n", i + 1, min_length);
	}
}