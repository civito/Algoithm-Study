#include<stdio.h>

int memo[10] = { 0 };
int n;
int cnt;

int promissing(int x, int y) {
	int i;

	if (x == 0)
		return 1;

	for (i = 0; i < x; i++) {
		if (memo[i] == y)
			return -1;
		else if ((memo[i] - y) == (x - i) || (y - memo[i]) == (x - i)){
			return -1;
		}
	}
	return 1;
}


void queens(int x) {
	int y, i, j;

	if (x == n) {
		cnt++;

		return;
	}
		
	for (y = 0; y < n; y++) {


		if (promissing(x, y) == 1) {
			memo[x] = y;
			queens(x + 1);
		}
	}
	return;
}


int main() {
	int testcase;
	int i;
	
	scanf("%d", &testcase);


	for (i = 0; i < testcase; i++) {
		scanf("%d", &n);
		cnt = 0;


		queens(0);


		printf("#%d %d\n", i+1, cnt);

	}


}