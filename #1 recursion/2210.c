#include<stdio.h>
#include<stdlib.h>

int **arr;
int cnt;
int num[6];

int Jump(int x, int y, int k) {
	int i;
	if (x >= 5 || y >= 5 || x < 0 || y < 0)
		return -1;
	num[k] = arr[x][y];

	if (k == 5) {
		for (i = 0; i < 6; i++) {
			printf("%d", num[i]);
		}
		cnt++;
		printf("\n");
	}

	else {
		Jump(x + 1, y, k + 1);
		Jump(x - 1, y, k + 1);
		Jump(x, y + 1, k + 1);
		Jump(x, y - 1, k + 1);
	}
}

int main() {
	int i, j, k;
	
	arr = (int**)malloc(sizeof(int*) * 5);
	for (int i = 0; i<5; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 5);
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			Jump(i, j, 0);
		}
	}

	printf("%d", cnt);
}