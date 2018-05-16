#include<stdio.h>
int map[101][101] = { 0, };

int xpos[100000] = { 0, };
int ypos[100000] = { 0, };

int pivot;
int N;
int d, g;
int pnt;

void cal(int g) {
	int j, i;
	for (i = 0; i < g; i++) {
		for (j = pivot-1; j >= 0; j--) {
			xpos[pnt] = xpos[pivot] + ypos[pivot] - ypos[j];
			ypos[pnt++] = xpos[j] - xpos[pivot] + ypos[pivot];
		}
		pivot = pnt - 1;
	}

	for (i = 0; i < pnt; i++) {
		map[ypos[i]][xpos[i]] = 1;
	}
}

int main() {
	int i, j;
	int count = 0;
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d %d %d", &xpos[0], &ypos[0], &d, &g);
		switch (d) {
		case 0:
			xpos[1] = xpos[0] + 1;
			ypos[1] = ypos[0];
			break;
		case 1:
			xpos[1] = xpos[0];
			ypos[1] = ypos[0] - 1;
			break;
		case 2:
			xpos[1] = xpos[0] - 1;
			ypos[1] = ypos[0];
			break;
		case 3:
			xpos[1] = xpos[0];
			ypos[1] = ypos[0] + 1;
			break;
		}
		pivot = 1;
		pnt = 2;
		cal(g);
	}
	for (i = 0; i < 99; i++) {
		for (j = 0; j < 99; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
				count++;
		}
	}

	printf("%d", count);
}