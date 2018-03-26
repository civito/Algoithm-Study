#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <string>

using namespace std;

int k;
int ans;
char num[6];
int numlen;

void Swap(char* a, char* b) {
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int is_same_num() {
	int i, j;
	
	for (i = 0; i < numlen; i++) {
		for (j = 0; j < numlen; j++) {
			if (num[i] == num[j] && i != j) {
				return 1;
			}
		}
	}

	return -1;
}


void sol(char* num, int pivot, int cnt) {
	int i;
	int index = pivot;
	int max = 0;
	int tmp, tmp2;


	if (ans < stoi(num)) {
		ans = stoi(num);
	}

	if (cnt == k) {
		return;
	}

	for (i = numlen - 1; i > pivot; i--) {
		if (num[i] - '0' > num[pivot] - '0' && num[i] - '0' > num[index] - '0')
			index = i;
	}

	if (index != pivot) {
		for (i = numlen - 1; i > pivot; i--) {
			if (num[i] - '0' == num[index] - '0') {
				Swap(&num[i], &num[pivot]);
				sol(num, pivot + 1, cnt + 1);
				Swap(&num[i], &num[pivot]);
			}
		}
	}
	else if (pivot == numlen - 1) {
		if((k-cnt)%2 == 1){
			if(is_same_num() == -1){
				tmp = ans % 100;
				ans -= tmp;
				tmp2 = tmp / 10;
				tmp %= 10;
				ans += tmp * 10 + tmp2;
			}
		}else{}
		return;
	}
	else {
		sol(num, pivot + 1, cnt);
	}
}

int main() {
	int i;
	int testcase;
	int cnt;

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		ans = 0;

		scanf("%s %d", num, &k);
		numlen = strlen(num);

		sol(num, 0, 0);

		printf("#%d %d", i + 1, ans);
		printf("\n");
	}
}