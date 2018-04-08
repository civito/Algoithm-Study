#include<stdio.h>

int A[8];
int B[8];
int C[8];
int D[8];

int check[3] = { 0 };

int apos = 0;
int bpos = 0;
int cpos = 0;
int dpos = 0;


void init() {
	apos = 0;
	bpos = 0;
	cpos = 0;
	dpos = 0;
}

void Check_Attach() {
	if (A[(apos + 2) % 8] != B[(bpos + 6) % 8])
		check[0] = 1;
	else
		check[0] = 0;


	if (B[(bpos + 2) % 8] != C[(cpos + 6) % 8])
		check[1] = 1;
	else
		check[1] = 0;


	if (C[(cpos + 2) % 8] != D[(dpos + 6) % 8])
		check[2] = 1;
	else
		check[2] = 0;
}


void rotateA(int DIR) {
	apos += 8 - DIR;
	apos %= 8;
}

void rotateB(int DIR) {
	bpos += 8 - DIR;
	bpos %= 8;
}

void rotateC(int DIR) {
	cpos += 8 - DIR;
	cpos %= 8;
}

void rotateD(int DIR) {
	dpos += 8 - DIR;
	dpos %= 8;
}
int main() {
	int testcase;
	int i, j;
	int K, sum;
	int dir, which;

	freopen("input.txt", "r", stdin);

	scanf("%d", &testcase);
	for (i = 0; i < testcase; i++) {
		init();
		sum = 0;
		scanf("%d", &K);

		for (j = 0; j < 8; j++) {
			scanf("%d", &A[j]);
		}
		for (j = 0; j < 8; j++) {
			scanf("%d", &B[j]);
		}
		for (j = 0; j < 8; j++) {
			scanf("%d", &C[j]);
		}
		for (j = 0; j < 8; j++) {
			scanf("%d", &D[j]);
		}

		for (j = 0; j < K; j++) {
			scanf("%d %d", &which, &dir);
			Check_Attach();

			switch (which) {
			case 1:
				rotateA(dir);
				if (check[0] == 1) {
					rotateB(-dir);
					if (check[1] == 1) {
						rotateC(dir);
						if (check[2] == 1) {
							rotateD(-dir);
						}
					}
				}
			break;

			case 2:
				rotateB(dir);
				if (check[0] == 1) {
					rotateA(-dir);
				}
				if (check[1] == 1) {
					rotateC(-dir);
					if (check[2] == 1) {
						rotateD(dir);
					}
				}
			break;

			case 3:
				rotateC(dir);
				if (check[2] == 1) {
					rotateD(-dir);
				}
				if (check[1] == 1) {
					rotateB(-dir);
					if (check[0] == 1) {
						rotateA(dir);
					}
				}
			break;
			
			case 4:
				rotateD(dir);
				if (check[2] == 1) {
					rotateC(-dir);
					if (check[1] == 1) {
						rotateB(dir);
						if (check[0] == 1) {
							rotateA(-dir);
						}
					}
				}
			break;
			}
		}

		if (A[apos] == 1)
			sum += 1;
		if (B[bpos] == 1)
			sum += 2;
		if (C[cpos] == 1)
			sum += 4;
		if (D[dpos] == 1)
			sum += 8;

		printf("#%d %d\n", i + 1, sum);

	}
}