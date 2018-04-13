#include<stdio.h>
int N;
int cnt;
int S[20][20];
int check[100] = { 0, }; // 초기화 필요
int sum, max;
int initx, inity;


void DFS(int x, int y, int DIR) {
//	printf("S[%d][%d], %d\n", y, x, DIR);

	if (x == initx && y == inity && DIR != 1) {
		if (cnt > max)
	//		printf("###\n");
			max = cnt;
		return;
	}

	if (DIR == 1) {
		if (x + 1 < N && y + 1 < N && check[S[y + 1][x + 1]] != 1) {
			cnt++;
			check[S[y + 1][x + 1]] = 1;
			DFS(x + 1, y + 1, 1);
			cnt--;
			check[S[y + 1][x + 1]] = 0;
		}
		if (x - 1 >= 0 && y + 1 < N && check[S[y + 1][x - 1]] != 1) {
			cnt++;
			check[S[y + 1][x - 1]] = 1;
			DFS(x - 1, y + 1, 2);
			cnt--;
			check[S[y + 1][x - 1]] = 0;
		}
	}else if (DIR == 2) {
		if (x - 1 >= 0 && y + 1 < N && check[S[y + 1][x - 1]] != 1) {
			cnt++;
			check[S[y + 1][x - 1]] = 1;
			DFS(x - 1, y + 1, 2);
			cnt--;
			check[S[y + 1][x - 1]] = 0;
		}
		if (x - 1 >= 0 && y - 1 >= 0 && check[S[y - 1][x - 1]] != 1) {
			cnt++;
			check[S[y - 1][x - 1]] = 1;
			DFS(x - 1, y - 1, 3);
			cnt--;
			check[S[y - 1][x - 1]] = 0;
		}
	}
	else if (DIR == 3) {
		if (x - 1 >= 0 && y - 1 >= 0 && check[S[y - 1][x - 1]] != 1) {
			cnt++;
			check[S[y - 1][x - 1]] = 1;
			DFS(x - 1, y - 1, 3);
			cnt--;
			check[S[y - 1][x - 1]] = 0;
		}
		if (x + 1 < N && y - 1 >= 0 && check[S[y - 1][x + 1]] != 1) {
			cnt++;
			check[S[y - 1][x + 1]] = 1;
			DFS(x + 1, y - 1, 4);
			cnt--;
			check[S[y - 1][x + 1]] = 0;
		}
	}
	else {
		if (x + 1 < N && y - 1 >= 0 && check[S[y - 1][x + 1]] != 1) {
			cnt++;
			check[S[y - 1][x + 1]] = 1;
			DFS(x + 1, y - 1, 4);
			cnt--;
			check[S[y - 1][x + 1]] = 0;
		}
	}
}



int main() {
	int testcase;
	int i, j, k;
	int val, MAX;
	freopen("input.txt", "r", stdin);

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		scanf("%d", &N);


		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				scanf("%d", &S[j][k]);
			}
		}

		MAX = 0;
		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				cnt = 0;
				max = 0;
				if (j + 1 < N && k + 1 < N) {
					initx = k;
					inity = j;
					check[S[j+1][k+1]] = 1;
					cnt++;
		//			printf("init : [%d %d]\n", k, j);
					DFS(k+1, j+1, 1);
					check[S[j+1][k+1]] = 0;
					if (MAX < max)
						MAX = max;
				}
			}
		}
		for (j = 0; j < 100; j++) {
			check[j] = 0;
		}
		if (MAX == 0) {
			printf("#%d %d\n", i + 1, -1);
		}
		else {
			printf("#%d %d\n", i + 1, MAX);
		}
		
	}
}