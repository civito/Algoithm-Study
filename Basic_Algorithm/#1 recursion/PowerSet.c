#include<stdio.h>

#define TRUE 1
#define FALSE 0

int include[5] = { 0, };
char data[5] = {'a','b','c','d','e'};

void Powerset(int k) {
	int i;
	if (k == 4) {
		for (i = 0; i < 5; i++) {
			if (include[i] == TRUE)
				printf("%c ", data[i]);
		}
		printf("\n");
	}
	else {
		include[k + 1] = FALSE;
		Powerset(k + 1);
		include[k + 1] = TRUE;
		Powerset(k + 1);
	}
}


int main() {
	Powerset(-1);
}