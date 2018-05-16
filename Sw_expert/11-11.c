#include<stdio.h>

int D, H, M;


int main() {
	int testcase, i, j;
	int T;
	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		scanf("%d %d %d", &D, &H, &M);
		T = (D * 1440) + (H * 60) + M - 16511;

		if (T >= 0) {
			printf("#%d %d\n ", i + 1, T);
		}
		else {
			printf("#%d -1\n ", i + 1 );
		}

		
	}


}