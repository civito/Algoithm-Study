#include<stdio.h>
#include<stdlib.h>

struct pos {
	int x;
	int y;

};

int N[50][50];
int check[14] = {0, };
struct pos chicken[14];
int chiknum = 0;
int M;
int num;
int MIN;
int s_MIN;
int SUM;

void cal() {
	int distance;
	SUM = 0;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			MIN = 1000000;
			if (N[i][j] == 1) {
				for (int k = 0; k < chiknum; k++) {
					if (check[k] == 1) {
						if (abs(i - chicken[k].y) + abs(j - chicken[k].x) < MIN)
							MIN = abs(i - chicken[k].y) + abs(j - chicken[k].x);
					}
				}
				SUM += MIN;
			}
		}
	}
}


void DFS(int cnt, int n) {
	if (n == M) {
		
		cal();
		for (int i = 0; i < chiknum; i++) {
			printf("%d ", check[i]);
		}
		printf("\n");
		printf("%d ", SUM);
		printf("\n");
		if (SUM < s_MIN) {
			s_MIN = SUM;
		}
		return;
	}

	if (cnt == chiknum)
		return;


	check[cnt] = 1;
	DFS(cnt + 1, n + 1);
	check[cnt] = 0;
	DFS(cnt + 1, n);
}


int main() {
	int i, j;
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &num, &M);
	s_MIN = 1000000;
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			scanf("%d", &N[i][j]);
			if (N[i][j] == 2) {
				chicken[chiknum].x = j;
				chicken[chiknum++].y = i;
			}
		}
	}

	DFS(0, 0);

	printf("%d", s_MIN);

}
