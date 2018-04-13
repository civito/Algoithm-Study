#include<stdio.h>
int N, M, R, C, L;


struct S {
	int x;
	int y;
	int DIR;
};

struct S S[50][50];
struct S Queue[400];
int check[50][50] = { 0, };
int cnt;
int front, back;

void Enqueue(struct S S) {
	Queue[front++] = S;
}

struct S Dequeue() {
	return Queue[back++];
}




void BFS() {
	struct S tmpS;
	int i, tmpf, tmpb;
	tmpf = front;
	tmpb = back;
	while (front != back && cnt != L) {
		for (i = 0; i< tmpf - tmpb; i++){
			tmpS = Dequeue();
			
		
			switch (tmpS.DIR) {
			case 1:
				if (tmpS.x - 1 >= 0 && check[tmpS.y][tmpS.x - 1] != 1) {
					if (S[tmpS.y][tmpS.x - 1].DIR == 1 || S[tmpS.y][tmpS.x - 1].DIR == 3 || S[tmpS.y][tmpS.x - 1].DIR == 4 || S[tmpS.y][tmpS.x - 1].DIR == 5) {
						check[tmpS.y][tmpS.x - 1] = 1;
						Enqueue(S[tmpS.y][tmpS.x - 1]);
					}
				}

				if (tmpS.x + 1 < M && check[tmpS.y][tmpS.x + 1] != 1) {
					if (S[tmpS.y][tmpS.x + 1].DIR == 1 || S[tmpS.y][tmpS.x + 1].DIR == 3 || S[tmpS.y][tmpS.x + 1].DIR == 6 || S[tmpS.y][tmpS.x + 1].DIR == 7) {
						check[tmpS.y][tmpS.x + 1] = 1;
						Enqueue(S[tmpS.y][tmpS.x + 1]);
					}
				}

				if (tmpS.y + 1 < N && check[tmpS.y + 1][tmpS.x] != 1) {
					if (S[tmpS.y + 1][tmpS.x].DIR == 1 || S[tmpS.y + 1][tmpS.x].DIR == 2 || S[tmpS.y+1][tmpS.x].DIR == 4 || S[tmpS.y+1][tmpS.x].DIR == 7) {
						check[tmpS.y+1][tmpS.x] = 1;
						Enqueue(S[tmpS.y+1][tmpS.x]);
					}
				}

				if (tmpS.y - 1 >= 0 && check[tmpS.y-1][tmpS.x] != 1) {
					if (S[tmpS.y-1][tmpS.x].DIR == 1 || S[tmpS.y-1][tmpS.x].DIR == 2 || S[tmpS.y - 1][tmpS.x].DIR == 5 || S[tmpS.y - 1][tmpS.x].DIR == 6) {
						check[tmpS.y - 1][tmpS.x] = 1;
						Enqueue(S[tmpS.y - 1][tmpS.x]);
					}
				}
				break;
			case 2:
				if (tmpS.y + 1 < N && check[tmpS.y + 1][tmpS.x] != 1) {
					if (S[tmpS.y + 1][tmpS.x].DIR == 1 || S[tmpS.y + 1][tmpS.x].DIR == 2 || S[tmpS.y + 1][tmpS.x].DIR == 4 || S[tmpS.y + 1][tmpS.x].DIR == 7) {
						check[tmpS.y + 1][tmpS.x] = 1;
						Enqueue(S[tmpS.y + 1][tmpS.x]);
					}
				}

				if (tmpS.y - 1 >= 0 && check[tmpS.y - 1][tmpS.x] != 1) {
					if (S[tmpS.y - 1][tmpS.x].DIR == 1 || S[tmpS.y - 1][tmpS.x].DIR == 2 || S[tmpS.y - 1][tmpS.x].DIR == 5 || S[tmpS.y - 1][tmpS.x].DIR == 6) {
						check[tmpS.y - 1][tmpS.x] = 1;
						Enqueue(S[tmpS.y - 1][tmpS.x]);
					}
				}
				break;
			case 3:
				if (tmpS.x - 1 >= 0 && check[tmpS.y][tmpS.x - 1] != 1) {
					if (S[tmpS.y][tmpS.x - 1].DIR == 1 || S[tmpS.y][tmpS.x - 1].DIR == 3 || S[tmpS.y][tmpS.x - 1].DIR == 4 || S[tmpS.y][tmpS.x - 1].DIR == 5) {
						check[tmpS.y][tmpS.x - 1] = 1;
						Enqueue(S[tmpS.y][tmpS.x - 1]);
					}
				}

				if (tmpS.x + 1 < M && check[tmpS.y][tmpS.x + 1] != 1) {
					if (S[tmpS.y][tmpS.x + 1].DIR == 1 || S[tmpS.y][tmpS.x + 1].DIR == 3 || S[tmpS.y][tmpS.x + 1].DIR == 6 || S[tmpS.y][tmpS.x + 1].DIR == 7) {
						check[tmpS.y][tmpS.x + 1] = 1;
						Enqueue(S[tmpS.y][tmpS.x + 1]);
					}
				}
				break;
			case 4:
				if (tmpS.x + 1 < M && check[tmpS.y][tmpS.x + 1] != 1) {
					if (S[tmpS.y][tmpS.x + 1].DIR == 1 || S[tmpS.y][tmpS.x + 1].DIR == 3 || S[tmpS.y][tmpS.x + 1].DIR == 6 || S[tmpS.y][tmpS.x + 1].DIR == 7) {
						check[tmpS.y][tmpS.x + 1] = 1;
						Enqueue(S[tmpS.y][tmpS.x + 1]);
					}
				}
				if (tmpS.y - 1 >= 0 && check[tmpS.y - 1][tmpS.x] != 1) {
					if (S[tmpS.y - 1][tmpS.x].DIR == 1 || S[tmpS.y - 1][tmpS.x].DIR == 2 || S[tmpS.y - 1][tmpS.x].DIR == 5 || S[tmpS.y - 1][tmpS.x].DIR == 6) {
						check[tmpS.y - 1][tmpS.x] = 1;
						Enqueue(S[tmpS.y - 1][tmpS.x]);
					}
				}
				break;
			case 5:
				if (tmpS.x + 1 < M && check[tmpS.y][tmpS.x + 1] != 1) {
					if (S[tmpS.y][tmpS.x + 1].DIR == 1 || S[tmpS.y][tmpS.x + 1].DIR == 3 || S[tmpS.y][tmpS.x + 1].DIR == 6 || S[tmpS.y][tmpS.x + 1].DIR == 7) {
						check[tmpS.y][tmpS.x + 1] = 1;
						Enqueue(S[tmpS.y][tmpS.x + 1]);
					}
				}

				if (tmpS.y + 1 < N && check[tmpS.y + 1][tmpS.x] != 1) {
					if (S[tmpS.y + 1][tmpS.x].DIR == 1 || S[tmpS.y + 1][tmpS.x].DIR == 2 || S[tmpS.y + 1][tmpS.x].DIR == 4 || S[tmpS.y + 1][tmpS.x].DIR == 7) {
						check[tmpS.y + 1][tmpS.x] = 1;
						Enqueue(S[tmpS.y + 1][tmpS.x]);
					}
				}
				break;
			case 6:
				if (tmpS.x - 1 >= 0 && check[tmpS.y][tmpS.x - 1] != 1) {
					if (S[tmpS.y][tmpS.x - 1].DIR == 1 || S[tmpS.y][tmpS.x - 1].DIR == 3 || S[tmpS.y][tmpS.x - 1].DIR == 4 || S[tmpS.y][tmpS.x - 1].DIR == 5) {
						check[tmpS.y][tmpS.x - 1] = 1;
						Enqueue(S[tmpS.y][tmpS.x - 1]);
					}
				}

				if (tmpS.y + 1 < N && check[tmpS.y + 1][tmpS.x] != 1) {
					if (S[tmpS.y + 1][tmpS.x].DIR == 1 || S[tmpS.y + 1][tmpS.x].DIR == 2 || S[tmpS.y + 1][tmpS.x].DIR == 4 || S[tmpS.y + 1][tmpS.x].DIR == 7) {
						check[tmpS.y + 1][tmpS.x] = 1;
						Enqueue(S[tmpS.y + 1][tmpS.x]);
					}
				}
				break;
			case 7:
				if (tmpS.x - 1 >= 0 && check[tmpS.y][tmpS.x - 1] != 1) {
					if (S[tmpS.y][tmpS.x - 1].DIR == 1 || S[tmpS.y][tmpS.x - 1].DIR == 3 || S[tmpS.y][tmpS.x - 1].DIR == 4 || S[tmpS.y][tmpS.x - 1].DIR == 5) {
						check[tmpS.y][tmpS.x - 1] = 1;
						Enqueue(S[tmpS.y][tmpS.x - 1]);
					}
				}
				if (tmpS.y - 1 >= 0 && check[tmpS.y - 1][tmpS.x] != 1) {
					if (S[tmpS.y - 1][tmpS.x].DIR == 1 || S[tmpS.y - 1][tmpS.x].DIR == 2 || S[tmpS.y - 1][tmpS.x].DIR == 5 || S[tmpS.y - 1][tmpS.x].DIR == 6) {
						check[tmpS.y - 1][tmpS.x] = 1;
						Enqueue(S[tmpS.y - 1][tmpS.x]);
					}
				}
				break;
			}
		}
		tmpf = front;
		tmpb = back;
		cnt++;
	}
}



int main() {
	int testcase;
	int i, j, k;
	int CNT;

	freopen("input.txt", "r", stdin);

	scanf("%d", &testcase);

	for (i = 0; i < testcase; i++) {
		cnt = 1;
		CNT = 0;
		front = 0;
		back = 0;
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);

		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				S[j][k].y = j;
				S[j][k].x = k;
				scanf("%d", &S[j][k].DIR);
			}
		}
		check[R][C] = 1;
		Enqueue(S[R][C]);
		BFS();

		for (j = 0; j < N; j++) {
			for (k = 0; k < M; k++) {
				if (check[j][k] == 1)
					CNT++;
				check[j][k] = 0;
			}
		}
		printf("#%d %d\n", i + 1, CNT);
	}
}