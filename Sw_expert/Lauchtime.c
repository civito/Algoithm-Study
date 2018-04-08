#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define A 1
#define B 2

#define MIN(a,b) (a)<(b)?(a):(b)
#define MAX(a,b) (a)>(b)?(a):(b)

int N;
int L[10][10];

int tempA[12];
int tempB[12];

int x[10];
int y[10];

int obx[2];
int oby[2];

int stairA = 0;
int stairB = 0;

int p_num;
int arr[11] = { 0, };

int val;
int Acnt;
int Bcnt;

void init() {
	stairA = 0;
	stairB = 0;
	val = 1000;
}

int compare(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

void cal() {
	int i;
	int Aval = -1;
	int Bval = -1;
	int Acnt = 0;
	int Bcnt = 0;
	int Acost = 0;
	int	Bcost = 0;

	for (i = 0; i < p_num; i++) {
		if (arr[i] == A) {
			Aval = abs(obx[0] - x[i]) + abs(oby[0] - y[i]);
			tempA[Acnt] = Aval;
			Acnt++;
		}
		if (arr[i] == B) {
			Bval = abs(obx[1] - x[i]) + abs(oby[1] - y[i]);
			tempB[Bcnt] = Bval;
			Bcnt++;
		}
	}

	if (Acnt != 0) {
		qsort(tempA, Acnt, sizeof(int), compare);
		if (Acnt > 3) {
			for (i = 3; i < Acnt; i++) {
				if (tempA[i - 3] + ((i / 3)*stairA) > tempA[i]) {
					tempA[i] = tempA[i - 3] + ((i / 3)*stairA);
				}
			}
		}
		Acost = tempA[Acnt - 1] + stairA + 1;
	}

	if (Bcnt != 0) {
		qsort(tempB, Bcnt, sizeof(int), compare);
		if (Bcnt > 3) {
			for (i = 3; i < Bcnt; i++) {
				if (tempB[i - 3] + ((i / 3)*stairB) > tempB[i]) {
					tempB[i] = tempB[i - 3] + ((i / 3)*stairB);
				}
			}
		}
		Bcost = tempB[Bcnt - 1] + stairB + 1;
	}

	//for (i = 0; i < Acnt; i++) {
	//	printf("tempA[%d] : %d\n", i, tempA[i]);
	//}
	//for (i = 0; i < Bcnt; i++) {
	//	printf("tempB[%d] : %d\n", i, tempB[i]);
	//}

	//printf("Acost : %d, Bcost : %d \n", Acost, Bcost);
	//printf("Val : %d \n", val);

	val = MIN(val, MAX(Acost, Bcost));
	//printf("max : %d \n", MAX(Acost, Bcost));
	//printf("Val : %d \n", val);
}

	


void dfs(int cnt) {
	
	if (cnt == p_num) {
		//printf("Val : %d \n", val);

	//	for (int i = 0; i < p_num; i++) {
	//		printf("%d ", arr[i]);
	//	}
	//	printf("\n");
		cal();
		return;
	}

	arr[cnt] = A;
	dfs(cnt + 1);
	arr[cnt] = B;
	dfs(cnt + 1);
}


int main() {
	int testcase;
	int i, j, k;
	freopen("input.txt", "r", stdin);

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		init();
		scanf("%d", &N);
		p_num = 0;

		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				scanf("%d", &L[j][k]);
				if (L[j][k] == 1) {
					x[p_num] = k;
					y[p_num] = j;
					p_num += 1;
				}
				else if (L[j][k] != 0 && L[j][k] != 1 && stairA == 0) {
					stairA = L[j][k];
					obx[0] = k;
					oby[0] = j;
				}
				else if (L[j][k] != 0 && L[j][k] != 1 && stairB == 0) {
					stairB = L[j][k];
					obx[1] = k;
					oby[1] = j;
				}
				else;
			}
		}

		dfs(0);

		printf("#%d %d\n", i+1, val);
	}


}
