#include<stdio.h>
#define INF 1000000

#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3

int Num[12] = { 0, };
int Op[4] = { 0, };

int N, sum;
int max;
int min;

void DFS(int cnt) {
	int tmp;

	if (cnt == N) {
		if (sum > max)
			max = sum;
		if (sum < min)
			min = sum;
		return;
	}

	if (Op[PLUS] > 0) {
		Op[PLUS]--;
		sum += Num[cnt];
		DFS(cnt + 1);
		Op[PLUS]++;
		sum -= Num[cnt];
	}
	if (Op[MINUS] > 0) {
		Op[MINUS]--;
		sum -= Num[cnt];
		DFS(cnt + 1);
		Op[MINUS]++;
		sum += Num[cnt];
	}
	if (Op[MUL] > 0) {
		Op[MUL]--;
		sum *= Num[cnt];
		DFS(cnt + 1);
		Op[MUL]++;
		sum /= Num[cnt];
	}
	if (Op[DIV] > 0) {
		Op[DIV]--;
		tmp = sum;
		sum /= Num[cnt];
		DFS(cnt + 1);
		Op[DIV]++;
		sum = tmp;
	}

}

int main() {
	int testcase;
	int i, j;
	freopen("input2.txt", "r", stdin);

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		sum = 0;
		scanf("%d", &N);

		for (j = 0; j < 4; j++) {
			scanf("%d", &Op[j]);
		}

		for (j = 0; j < N; j++) {
			scanf("%d", &Num[j]);
		}
		max = -INF;
		min = INF;
		sum = Num[0];
		DFS(1);

		printf("#%d %d\n", i + 1, max - min);

	}

}