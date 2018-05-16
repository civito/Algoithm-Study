#include<stdio.h>
int room[201] = { 0, };

int N;

void init() {
	for (int i = 0; i < 201; i++) {
		room[i] = 0;
	}
}

int findmax() {
	int Max = 0;
	for (int i = 0; i < 201; i++) {
		if (room[i] > Max) {
			Max = room[i];
		}
	}

	return Max;
}

int main() {
	int i, j, k, testcase;
	int from, to;
	freopen("input.txt", "r", stdin);

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		init();
		scanf("%d", &N);

		for (j = 0; j < N; j++) {
			scanf("%d %d", &from, &to);
			if(to > from){
				for (k = ((from + 1 ) / 2); k <= ((to+1) / 2); k++) {
					room[k] += 1;
				}
			}
			else {
				for (k = ((to + 1) / 2); k <= ((from + 1) / 2); k++) {
					room[k] += 1;
				}
			}
		}
		printf("#%d %d\n", i + 1, findmax());
	}
}