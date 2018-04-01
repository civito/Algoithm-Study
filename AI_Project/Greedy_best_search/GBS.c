#include<stdio.h>
#include <math.h>
#define INF 10000

struct N {
	int xpos;
	int ypos;
	int heuri;
	int val;
};

struct N Queue[INF];

int size = 0;

int row;
int col;

int time = 0;

struct N N[500][500];
int H[500][500] = { 0, };

void swap(struct N* a, struct N * b) {
	struct N tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void MinHeapify(int i) {
	int smallest;
	if ((2 * i <= size) && (Queue[2 * i].heuri < Queue[i].heuri)) {
		smallest = 2 * i;
	}
	else {
		smallest = i;
	}

	if ((2 * i + 1 <= size) && (Queue[2 * i + 1].heuri < Queue[smallest].heuri)) {
		smallest = 2 * i + 1;
	}

	if (smallest != i) {
		swap(&Queue[i], &Queue[smallest]);
		MinHeapify(smallest);
	}
}

void BuildHeap() {
	int i;

	for (i = (size / 2); i > 0; i--) {
		MinHeapify(i);
	}
}


void Enqueue(struct N N) {
	//	printf("N[%d][%d]\n", N.ypos, N.xpos);
	time++;
	Queue[++size] = N;
	//	printf("%d %d\n", Queue[size].ypos, Queue[size].xpos);
}


struct N Extract_Min() {
	struct N min;

	min = Queue[1];
	Queue[1] = Queue[size--];
	MinHeapify(1);

	return min;
}

struct N Dequeue() {
	BuildHeap();
	return Extract_Min();
}



void cal(int y, int x) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (N[i][j].val == 2) {
				H[i][j] += abs(i - y) + abs(j - x);
				//printf("H[%d][%d] = abs(%d - %d) + abs(%d - %d) = %d\n", i, j, i, y, j, x, H[i][j]);
			}
		}
	}
}


void Make_heuristic() {
	int i, j;

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (N[i][j].val == 4) {
				//printf("N[%d][%d]\n", i, j);
				cal(i, j);
			}
		}
	}

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			N[i][j].heuri = H[i][j];
		}
	}

}

void GBS(int x, int y) {
	struct N tmp;
	//	printf("%d %d\n", x, y);
	Enqueue(N[y][x]);

	while (size != 0) {
		tmp = Dequeue();
		//		printf("N[tmp.ypos][tmp.xpos] == N[%d][%d]\n", tmp.ypos, tmp.xpos);

		if (N[tmp.ypos + 1][tmp.xpos].val == 2) {
			Enqueue(N[tmp.ypos + 1][tmp.xpos]);
			N[tmp.ypos + 1][tmp.xpos].val = 5;
		}
		if (N[tmp.ypos - 1][tmp.xpos].val == 2) {
			Enqueue(N[tmp.ypos - 1][tmp.xpos]);
			N[tmp.ypos - 1][tmp.xpos].val = 5;
		}
		if (N[tmp.ypos][tmp.xpos + 1].val == 2) {
			Enqueue(N[tmp.ypos][tmp.xpos + 1]);
			N[tmp.ypos][tmp.xpos + 1].val = 5;
		}
		if (N[tmp.ypos][tmp.xpos - 1].val == 2) {
			Enqueue(N[tmp.ypos][tmp.xpos - 1]);
			N[tmp.ypos][tmp.xpos - 1].val = 5;
		}

		if (N[tmp.ypos + 1][tmp.xpos].val == 4 ||
			N[tmp.ypos - 1][tmp.xpos].val == 4 ||
			N[tmp.ypos][tmp.xpos + 1].val == 4 ||
			N[tmp.ypos][tmp.xpos - 1].val == 4)
			break;

	}
}



void Print() {
	int i, j;
	int count = 0;

	for (i = 0; i < 12; i++) {
		for (j = 0; j < 13; j++) {
			printf("%d", N[i][j].val);
			if (N[i][j].val == 5)
				count++;
		}
		printf("\n");
	}
	printf("---\n");

	/*	for (i = 0; i < 12; i++) {
	for (j = 0; j < 13; j++) {
	printf("%d  ", H[i][j]);

	}
	printf("\n");
	}
	printf("---\n");*/

	printf("length = %d\n", count);
	printf("time = %d\n", time);
}


int main() {
	int i, j;
	int startx, starty;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);



	scanf("%d %d", &row, &col);

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			scanf("%d", &N[i][j].val);
			if (N[i][j].val == 3) {
				starty = i;
				startx = j;
			}
			N[i][j].xpos = j;
			N[i][j].ypos = i;
		}
	}
	Make_heuristic();
	GBS(startx, starty);
	Print();
}