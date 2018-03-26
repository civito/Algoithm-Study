#include<stdio.h>

int Queue[8] = { -1, -1, -1, -1, -1, -1, -1, -1};
int front = -1;
int back = -1;

int G[8][8] = { { 0,1,1,0,0,0,0,0 },
				{ 1,0,0,1,1,0,0,0 },
				{ 1,0,0,0,1,0,1,1 },
				{ 0,1,0,0,1,0,0,0 },
				{ 0,1,1,1,0,1,0,0 },
				{ 0,0,0,0,1,0,0,0 },
				{ 0,0,1,0,0,0,0,1 },
				{ 0,0,1,0,0,0,1,0 },
			   };
int Visit[8] = { 0, };
int Pre[8] = { -1,-1,-1,-1,-1,-1,-1,-1 };

void Enqueue(int n) {
	if (front < 7)
		Queue[++front] = n;
	else
		printf("Enqueue Error");
}

int Dequeue() {
	if (back < front)
		return Queue[++back];
	else
		return -1;
}

void DFS(int s) {
	int v;
	int i;

	Visit[s] = 1;
	Enqueue(s);

	while (front != back) {
		v = Dequeue();
		printf("%d ", v+1);
		for (i = 0; i < 8; i++) {
			if (G[v][i] == 1 && Visit[i] == 0) {
				Enqueue(i);
				Visit[i] = 1;
				Pre[i] = v;
			}		
		}
	}
}

void PrintRoute(int s, int v) {
	if (s == v)
		printf("%d ", s+1);
	else if (Pre[v] == -1)
		printf("There is no Route\n");
	else {
		PrintRoute(s, Pre[v]);
		printf("%d ", v+1);
	}
}

int main() {

	DFS(0);
	printf("\n");

	PrintRoute(0, 5);

}