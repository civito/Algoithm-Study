#include<stdio.h>
#define A 0
#define B 1

int Com[13] = { 0, };
int tmparr[13] = { 0, };

int S[13][20] = { 0, };
int SS[13][20] = { 0, };

int D, W, K;
int FLAG;

int is_there(int col) {
	int i;
	int cnt = 1;

	for (i = 1; i < D; i++) {
		if (S[i][col] == S[i - 1][col])
			cnt += 1;
		else
			cnt = 1;

		if (cnt >= K)
			return 1;

	}
	return -1;
}

int check_row() {
	int i;

	for (i = 0; i < W; i++) {
		if (is_there(i) == 1);
		else
			return -1;
	}
	return 1;
}


void paste(int row) {
	int i;

	for (i = 0; i < W; i++) {
		S[row][i] = SS[row][i];
	}
}

void coloring(int num, int row) {
	int i;
	for (i = 0; i < W; i++) {
		S[row][i] = num;
	}
}

void color(int cnt, int j, int k) {
	int i, a, b;
	if (j == cnt) {
		
		if (check_row() == 1) {
			FLAG = 1;
		}
			
		return;
	}

	for (i = k+1; i < D; i++) {
		if (Com[i] == 1) {
			coloring(A, i);
			color(cnt, j + 1, i);
			coloring(B, i);
			color(cnt, j + 1, i);
			paste(i);
		}
	}
}


void DFS(int cnt, int i, int j) {
	int k, q;

	if (i == cnt) {
		color(cnt, 0, - 1);
		return;
	}

	for (k = j + 1; k < D; k++) {
		Com[k] = 1;
		DFS(cnt, i + 1, k);
		Com[k] = 0;
	}
}

int main() {
	int testcase;
	int i, j, k;
	int cnt;

	freopen("input.txt", "r", stdin);

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		scanf("%d %d %d", &D, &W, &K);

		FLAG = 0;

		for (j = 0; j < D; j++) {
			for (k = 0; k < W; k++) {
				scanf("%d", &S[j][k]);
				SS[j][k] = S[j][k];
			}
		}

		cnt = 0;
		if (check_row() == 1);
		else {
			cnt = 1;
			while (1) {
				DFS(cnt, 0, -1);
				if (FLAG == 1) {
					break;
				}
				cnt++;
			}
		}
		printf("#%d %d\n", i+1, cnt);
	}
}