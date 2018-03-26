#include<stdio.h>

#define nonblob 0
#define blob 1
#define already 2

int Cells[8][8] = {
	{1,0,0,0,0,0,0,1},
	{0,1,1,0,0,1,0,0},
	{1,1,0,0,1,0,1,0},
	{0,0,0,0,0,1,0,0},
	{0,1,0,1,0,1,0,0},
	{0,1,0,1,0,1,0,0},
	{1,0,0,0,1,0,0,1},
	{0,1,1,0,0,1,1,1}
};
int N = 8;


int CountingBlob(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= N || Cells[x][y] != blob)
		return 0;
	else {
		Cells[x][y] = already;
		return (1 + CountingBlob(x - 1, y) + CountingBlob(x + 1, y) + CountingBlob(x, y - 1) + CountingBlob(x, y + 1)
			+ CountingBlob(x - 1, y - 1) + CountingBlob(x - 1, y + 1) + CountingBlob(x + 1, y - 1) + CountingBlob(x + 1, y + 1));
	}

}


int main() {
	int x, y;

	scanf("%d %d", &x, &y);

	printf("%d\n",CountingBlob(x,y));

}