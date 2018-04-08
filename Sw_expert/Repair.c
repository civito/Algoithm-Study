#include<stdio.h>

#define CNT 0
#define IDX 1

#define E 2000

int repair[21][2] = { 0, };
int recept[21][2] = { 0, };

int pA = 0;
int pB = 0;
int historyA[1001] = { 0, };
int historyB[1001] = { 0, };

int N, M, K, A, B;
int a[21] = { 0, };
int b[21] = { 0, };
int t[1001] = { 0, };

int cnt;
int repair_front = 0;
int repair_back = 0;

int recept_front = 0;
int recept_back = 0;

int repair_wait[1001] = { 0, };
int recept_wait[1001] = { 0, };

void init() {
	int j;
	repair_front = 0;
	repair_back = 0;
	recept_front = 0;
	recept_back = 0;
	pA = 0;
	pB = 0;

	for (j = 0; j < M; j++) {
		repair[j][CNT] = E;
		repair[j][IDX] = E;
	}

	for (j = 0; j < N; j++) {
		recept[j][CNT] = E;
		recept[j][IDX] = E;
	}

	cnt = 0;
}

void repair_pop(int idx) {
	repair[idx][CNT] = E;
	repair[idx][IDX] = E;
}
int is_repair_waiting() {
	if (repair_back == repair_front)
		return -1;
	else
		return 1;
}
int is_repair_extra() {
	int i;
	for (i = 0; i < M; i++) {
		if (repair[i][IDX] == E)
			return 1;
	}
	return -1;
}

int pop_rep_wait() {
	return repair_wait[repair_back++];
}

void recept_pop(int idx) {
	recept[idx][CNT] = E;
	recept[idx][IDX] = E;
}

int is_recept_waiting() {
	if (recept_back == recept_front)
		return -1;
	else
		return 1;
}

int is_recept_extra(){
	int i;
	for (i = 0; i < N; i++) {
		if (recept[i][IDX] == E)
			return 1;
	}
	return -1;
}

int pop_rec_wait() {
	return recept_wait[recept_back++];
}


int main() {
	int testcase;
	int i, j, k;
	int sum;
	int Index;

	freopen("input.txt", "r", stdin);

	scanf("%d", &testcase);


	for (i = 0; i < testcase; i++) {
		scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
		init();
		sum = 0;

		for (j = 0; j < N; j++) {
			scanf("%d", &a[j]);
		}

		for (j = 0; j < M; j++) {
			scanf("%d", &b[j]);
		}

		for (j = 0; j < K; j++) {
			scanf("%d", &t[j]);
		}

		while (cnt < 120000) {
			// repair
			for (j = 0; j < M; j++) {
				if (cnt - repair[j][CNT] == b[j])
					repair_pop(j);
			}

			// repair_wait
			if (is_repair_waiting() == 1) {
				if (is_repair_extra() == 1) {
					for (j = 0; j < M; j++) {
						if (repair[j][IDX] == E) {

							repair[j][IDX] = pop_rep_wait();
							if (j == B - 1)
								historyB[pB++] = repair[j][IDX];
							repair[j][CNT] = cnt;
						}
						if (is_repair_waiting() == -1)
							break;
					}
				}
			}


			// recept
			for (j = 0; j < N; j++) {
				if (cnt - recept[j][CNT] == a[j]) {
					Index = recept[j][IDX];
					recept_pop(j);
					if (is_repair_extra() == 1) {
						for (k = 0; k < M; k++) {
							if (repair[k][IDX] == E) {
								if (k == B - 1)
									historyB[pB++] = Index;
								repair[k][IDX] = Index;
								repair[k][CNT] = cnt;
								break;
							}
						}
					}
					else {
						repair_wait[repair_front++] = Index;
					}
				}
			}


			// recept_wait
			if (is_recept_waiting() == 1) {
				if (is_recept_extra() == 1) {
					for (j = 0; j < N; j++) {
						if (recept[j][IDX] == E) {
							recept[j][IDX] = pop_rec_wait();
							if (j == A - 1)
								historyA[pA++] = recept[j][IDX];
							recept[j][CNT] = cnt;
						}
						if (is_recept_waiting() == -1)
							break;
					}
				}
			}


			//entrance
			for (j = 0; j < K; j++) {
				if (cnt == t[j]) {
					if (is_recept_extra() == 1) {
						for (k = 0; k < N; k++) {
							if (recept[k][IDX] == E) {
								if (k == A - 1)
									historyA[pA++] = j;
								recept[k][IDX] = j;
								recept[k][CNT] = cnt;
								break;
							}
						}
					}
					else {
						recept_wait[recept_front++] = j;
					}
				}
			}
			cnt++;
		}
		for (j = 0; j < pA; j++) {
			for (k = 0; k < pB; k++) {
					
				if (historyA[j] == historyB[k])
					sum += historyA[j] + 1;
			}
		}
		if (sum == 0) {
			printf("#%d -1\n", i + 1);
		}else
		printf("#%d %d\n", i + 1, sum);

	}
}