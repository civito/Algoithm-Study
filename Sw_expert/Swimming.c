#include<stdio.h>

#define DAY 1
#define MONTH 2
#define TMONTH 3

int dfee, mfee, tmfee, yfee;

int S[12];
int C[12] = { 0, };
int check[12];
int num;
int min;


int cal() {
	int i, j;
	int sum = 0;


	for (i = 0; i < 12; i++) {
		if (C[i] == DAY && check[i] != 1) {
			sum += S[i] * dfee;
			check[i] = 1;
		}
		else if (C[i] == MONTH && check[i] != 1) {
			sum += mfee;
			check[i] = 1;
		}
		else if (C[i] == TMONTH && check[i] != 1) {
			sum += tmfee;
			for (j = 0; j < 3; j++) {
				if (i + j <12) {
					check[(i + j)] = 1;
				}
			}
		}
		else;
	}

	for (i = 0; i < 12; i++) {
		check[i] = 0;
	}
	return sum;
}


void DFS(int j, int cnt) {
	int i, val;
	if (cnt == num) {
		val = cal();
		if (val < min)
			min = val;
		return;
	}

	for (i = j + 1; i < 12; i++) {
		if (S[i] != 0) {
			C[i] = DAY;
			DFS(i, cnt + 1);
			C[i] = MONTH;
			DFS(i, cnt + 1);
			C[i] = TMONTH;
			DFS(i, cnt + 1);
		}
	}
}


int main() {
	int testcase;
	int i, j, k;

	freopen("input.txt", "r", stdin);
	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		scanf("%d %d %d %d", &dfee, &mfee, &tmfee, &yfee);
		num = 0;
		min = 10000;
		for (j = 0; j < 12; j++) {
			scanf("%d", &S[j]);
			if (S[j] != 0) {
				num++;
			}
			C[j] = 0;
		}
		DFS(-1, 0);
		if (min < yfee) {
			printf("#%d %d\n", i + 1, min);
		}
		else
			printf("#%d %d\n", i + 1, yfee);
	}
}
