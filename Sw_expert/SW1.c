#include<stdio.h>
int N[50][50] = { 0, };
int n;

void Pos(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n) {
		return;
	}
	else {
		N[x][y] = 1;
	}
}

void colorA(int x, int y) {
	Pos(x,y);
	Pos(x-1, y);
	Pos(x, y-1);
	Pos(x+1, y);
	Pos(x, y+1);
}

void colorB(int x, int y) {
	Pos(x, y);
	Pos(x - 1, y);
	Pos(x, y - 1);
	Pos(x + 1, y);
	Pos(x, y + 1);
	Pos(x - 2, y);
	Pos(x, y - 2);
	Pos(x + 2, y);
	Pos(x, y + 2);
}

void colorC(int x, int y) {
	Pos(x, y);
	Pos(x - 1, y);
	Pos(x, y - 1);
	Pos(x + 1, y);
	Pos(x, y + 1);
	Pos(x - 2, y);
	Pos(x, y - 2);
	Pos(x + 2, y);
	Pos(x, y + 2);
	Pos(x - 3, y);
	Pos(x, y - 3);
	Pos(x + 3, y);
	Pos(x, y + 3);

}

int main() {
	int  i,j;
	int cnt = 0;
	int A[4][2];
	int B[3][2];
	int C[2][2];

	scanf("%d", &n);
	
	for (i = 0; i < 4; i++) {
		scanf("%d %d", &A[i][0], &A[i][1]);
		colorA(A[i][0], A[i][1]);
	}
	for (i = 0; i < 3; i++) {
		scanf("%d %d", &B[i][0], &B[i][1]);
		colorB(B[i][0], B[i][1]);
	}
	for (i = 0; i < 2; i++) {
		scanf("%d %d", &C[i][0], &C[i][1]);
		colorC(C[i][0], C[i][1]);
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", N[i][j]);
			if (N[i][j] == 0)
				cnt++;
		}
		printf("\n");
	}

	printf("%d \n", cnt);






}