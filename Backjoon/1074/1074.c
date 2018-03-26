#include<stdio.h>

int power(int N) {
	int tmp = 1;
	int i;

	for (i = 0; i < N; i++) {
		tmp *= 2;
	}

	return tmp;
}

int RF(int N, int r, int c) {
	if (N == 0) {
		return 0;
	}

	if (c < power(N - 1) && r < power(N - 1)) {
		return RF(N - 1, r, c);
	}
	else if (c >= power(N - 1) && r < power(N - 1)) {
		return power(N-1)*power(N - 1) + RF(N - 1, r , c- power(N - 1));
	}
	else if (c < power(N - 1) && r >= power(N - 1)) {
		return power(N - 1)*power(N - 1) * 2 + RF(N - 1, r - power(N - 1), c );
	}
	else {
		return power(N - 1)*power(N - 1) * 3 + RF(N - 1, r - power(N - 1), c - power(N - 1));
	}
}



int main() {
	int N, r, c;

	scanf("%d %d %d", &N, &r, &c);

	printf("%d", RF(N, r, c));

}