#include<stdio.h>
int N, X;
int mat[20][20] = { 0, };
int c[20][20] = { 0, };


int check_back_row(int row, int n) {
	int i, a;

	a = mat[row][n];

	for (i = n; i > n - X; i--) {
		if (i < 0 || mat[row][i] != a || c[row][i] == 1)
			return -1;
		else
			c[row][i] = 1;
	}
	return 1;
}

int check_front_row(int row, int n) {
	int i, a;

	a = mat[row][n];

	for (i = n; i < n + X; i++) {
		if (i >= N || mat[row][i] != a || c[row][i] == 1)
			return -1;
		else
			c[row][i] = 1;
	}
	return 1;
}

int check_row(int row) {
	int a, i;

	a = mat[row][0];

	for (i = 1; i < N; i++) {
//		printf("mat[%d][%d] = %d\n", row, i, mat[row][i]);
//		printf("a = %d\n", a);
		if (mat[row][i] == a) {
		}
		else if (mat[row][i] == a + 1) {
			a = mat[row][i];
			if (check_back_row(row, i - 1) == -1)
				return -1;
		}
		else if (mat[row][i] == a - 1) {
			a = mat[row][i];
			if (check_front_row(row, i) == -1)
				return -1;
		}
		else {
			return -1;
		}
	}



	return 1;
}

int check_back_col(int col, int n) {
	int i, a;

	a = mat[n][col];

	for (i = n; i > n - X; i--) {
		if (i >= N || mat[i][col] != a || c[i][col] == 1)
			return -1;
		else
			c[i][col] = 1;
	}
	return 1;
}

int check_front_col(int col, int n) {
	int i, a;

	a = mat[n][col];

	for (i = n; i < n + X; i++) {
		if (i >= N || mat[i][col] != a || c[i][col] == 1)
			return -1;
		else
			c[i][col] = 1;
	}
	return 1;
}

int check_col(int col) {
	int a, i;

	a = mat[0][col];

	for (i = 1; i < N; i++) {
		if (mat[i][col] == a) {
		}
		else if (mat[i][col] == a + 1) {
			a = mat[i][col];
			if (check_back_col(col, i - 1) == -1)
				return -1;
		}
		else if (mat[i][col] == a - 1) {
			a = mat[i][col];
			if (check_front_col(col, i) == -1)
				return -1;
		}
		else {
			return -1;
		}
	}



	return 1;
}




int main() {
	int testcase;
	int i, j, k;
	int cnt;

	freopen("input.txt", "r", stdin);
	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		cnt = 0;
		scanf("%d %d", &N, &X);

		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				scanf("%d", &mat[j][k]);
				//printf("%d ", mat[j][k]);
			}
		}

		for (j = 0; j < N; j++) {
			if (check_row(j) == 1) {
				//printf("row j = %d\n", j);
				cnt++;
			}
			for (k = 0; k < N; k++) {
				c[j][k] = 0;
			}

			if (check_col(j) == 1){
				//printf("col j = %d\n", j);
				cnt++;
			}
			for (k = 0; k < N; k++) {
				c[k][j] = 0;
			}
		}
		printf("#%d %d\n",i+1, cnt);
	}
}