#include<stdio.h>

#define TRUE 1
#define FALSE 0

int *col;
int N;

int Ispromiss(int level) {
	int i;

	for (i = level+1; i < N; i++) {
		if (col[level] == col[i])
			return FALSE;
		else if ((i - level == col[level] - col[i]) || (i - level == col[i] - col[level]))
			return FALSE;
	}
	return TRUE;
}


int queen(int level) {
	int  i,j;

	if (!Ispromiss(level))
		return FALSE;
	else if (level == 0) {
		for (i = 0; i < N; i++) {
			for (j = 0; j < col[i]; j++) {
				printf(" ");
			}
			printf("*\n");
		}
		return TRUE;
	}
	else {
		for (i = 0; i < N; i++) {
			col[level-1] = i;
			if (queen(level - 1))
				return TRUE;
		}
		return FALSE;
	}
}


int main() {
	scanf("%d", &N);

	col = malloc(sizeof(int)*N);
	
	if (queen(N))
		printf("SUCCESS!\n");
	else printf("FAIL!\n");
}