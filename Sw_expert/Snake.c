#include<stdio.h>
#define APPLE -1

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

int N[102][102] = { 0, };
int L[102] = { 0, };
char C[102];

int Num;
int Lnum;

int sec;
int count;
int xpos, ypos;
int DIR;
int Lcnt;

void init() {
	sec = 0;
	count = 1;
	xpos = 1;
	ypos = 1;
	DIR = RIGHT;
	N[ypos][xpos] = 1;
	Lcnt = 0;
}

void tic_toc() {
	sec++;
}

void Minus(){
	int i, j;

	for (i = 1; i <= Num; i++) {
		for (j = 1; j <= Num; j++) {
			if (N[i][j] > 0)
				N[i][j] --;
		}
	}
}



void Switch_dir() {
	switch (DIR) {
	case RIGHT :
		if (C[Lcnt] == 'D')
			DIR = DOWN;
		else
			DIR = UP;
		break;
	case LEFT : 
		if (C[Lcnt] == 'D')
			DIR = UP;
		else
			DIR = DOWN;
		break;
	case UP:
		if (C[Lcnt] == 'D')
			DIR = RIGHT;
		else
			DIR = LEFT;
		break;
	case DOWN:
		if (C[Lcnt] == 'D')
			DIR = LEFT;
		else
			DIR = RIGHT;
		break;

	}
}



int main() {
	int k, i, j;
	int row, col;
	

	scanf("%d", &Num);

	scanf("%d", &k);

	for (i = 0; i < k; i++) {
		scanf("%d %d", &row, &col);
		N[row][col] = APPLE;
	}

	scanf("%d", &Lnum);

	for (i = 0; i < Lnum; i++) {
		scanf("%d %c", &L[i], &C[i]);
	}

	init();
	
	while (1) {
		tic_toc();

		switch (DIR) {
		case RIGHT:
			xpos += 1;
			break;
		case LEFT:
			xpos -= 1;
			break;
		case UP:
			ypos -= 1;
			break;
		case DOWN:
			ypos += 1;
			break;
		}

		if (N[ypos][xpos] == APPLE) {
			count++;
		}
		else if (N[ypos][xpos] > 0) {
			break;
		}
		else {
			Minus();
		}

		if (xpos > Num || xpos < 1 || ypos < 1 || ypos > Num)
			break;

		N[ypos][xpos] = count;

		if (sec == L[Lcnt]) {
			Switch_dir();
			Lcnt++;
		}
		
		for (i = 1; i <= Num; i++) {
			for (j = 1; j <= Num; j++) {
				printf("%d ", N[i][j]);
			}
			printf("\n");
		}
		printf("[ %d , %d ]  %d sec\n", xpos, ypos, sec);
		
	}

	printf("%d\n", sec);
}
