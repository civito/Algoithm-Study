#include<stdio.h>
int Amax;
int Bmax;

int A[5] = { 0, };
int B[5] = { 0, };
int cA[5] = { 0, };
int cB[5] = { 0, };

int N, M, C;
int S[10][10];

void Acal() {
	int i;
	int sum = 0;
	int tmp = 0;

	for (i = 0; i < M; i++) {
		if (cA[i] == 1) {
			sum += A[i];
			tmp += A[i] * A[i];
		}
	}
	if (sum > C)
		return;

	if (Amax < tmp)
		Amax = tmp;

}

void Bcal() {
	int i;
	int sum = 0;
	int tmp = 0;

	for (i = 0; i < M; i++) {
		if (cB[i] == 1) {
			sum += B[i];
			tmp += B[i] * B[i];
		}
	}
	if (sum > C)
		return;

	if (Bmax < tmp)
		Bmax = tmp;
}


void ADFS(int cnt) {
	if (cnt == M) {
		Acal();
		return;
	}
	cA[cnt] = 1;
	ADFS(cnt + 1);
	cA[cnt] = 0;
	ADFS(cnt + 1);
}

void BDFS(int cnt) {
	if (cnt == M) {
		Bcal();
		return;
	}
	cB[cnt] = 1;
	BDFS(cnt + 1);
	cB[cnt] = 0;
	BDFS(cnt + 1);
}


int main() {
	int testcase;
	int i, j, k, z, q, r;
	int tmp;
	int MAX;

	freopen("input.txt", "r", stdin);


	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		MAX = 0;
		scanf("%d %d %d", &N, &M, &C);
		
		Bmax = 0;

		for (j = 0; j < N; j++) {
			for (k = 0; k < N; k++) {
				scanf("%d", &S[j][k]);
			}
		}

		for (j = 0; j < N; j++) {
			for (k = 0; k <= N - M; k++) {
				tmp = k;
				for (q = 0; q < M; q++) {
					A[q] = S[j][tmp++];
				}
				Amax = 0;
				ADFS(0);
				//printf("AAAAA%d\n", Amax);
				for (z = j; z < N; z++) {
					if (z == j) {
						for (r = k + M; r <= N - M; r++) {
							tmp = r;
							for (q = 0; q < M; q++) {
								B[q] = S[z][tmp++];
							}
							BDFS(0);
					//		printf("1.%d\n", Bmax);
						}
					}
					else {
						for (r = 0; r <= N - M; r++) {
							tmp = r;
							for (q = 0; q < M; q++) {
								B[q] = S[z][tmp++];
							}
							BDFS(0);
						//	printf("2.%d\n", Bmax);
						}
					}
					
				}
				//printf("3.%d\n", Bmax);
				if (MAX < Amax+Bmax)
					MAX = Amax + Bmax;
				Bmax = 0;
			}
		}
		printf("#%d %d\n", i + 1, MAX);
	}
}