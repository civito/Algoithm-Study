#include<stdio.h>

int main() {
	int p[4] = { 10,100,5,50 };
	int m[3][3] = { 0, };
	int i, j, k, r;
	int Min;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3 - i; j++) {
			Min = 1000000;
			k = j + i;
			if (j == k)
				m[j][k] = 0;
			else {
				for (r = 0; r < k; r++) {
					if (Min > m[j][r] + m[r + 1][k] + p[j] * p[k + 1] * p[r + 1])
						Min = m[j][r] + m[r + 1][k] + p[j] * p[k + 1] * p[r + 1];
				}
				m[j][k] = Min;
			}
		}
	}

	printf("%d\n", m[0][2]);

}