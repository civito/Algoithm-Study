#include<stdio.h>

#define white 0 // not visited
#define black 1 // wall
#define green 2 // route
#define red 3 // not route

#define Passed 4

#define TRUE 1
#define FALSE 0

int maze[8][8] = {
	{ 0,0,0,0,0,0,0,1 },
	{ 0,1,1,0,1,1,0,1 },
	{ 0,0,0,1,0,0,0,1 },
	{ 0,1,0,0,1,1,0,0 },
	{ 0,1,1,1,0,0,1,1 },
	{ 0,1,0,0,0,1,0,1 },
	{ 0,0,0,1,0,0,0,1 },
	{ 0,1,1,1,0,1,0,0 }
};
int N = 8;

int FindMaze(int x, int y) {
	if (x < 0 || y < 0 || x>=N || y>=N || maze[x][y] != white) {
		return FALSE;
	}
	else if (x == N-1 && y == N-1) {
		maze[x][y] = green;
		return TRUE;
	}
	else {
		maze[x][y] = green;
		if (FindMaze(x - 1, y) || FindMaze(x + 1, y) || FindMaze(x, y-1 ) || FindMaze(x, y+1)) {
			return TRUE;
		}
		maze[x][y] = red;
		return FALSE;
	}
}

void PrintRoute(int x, int y) {
	if (x == N - 1 && y == N - 1 && maze[x][y] == green);
	else if (maze[x][y] != green);
	else {
		printf("(%d,%d)\n", x, y);
		maze[x][y] = Passed;
		PrintRoute(x - 1, y);
		PrintRoute(x + 1, y);
		PrintRoute(x , y -1 );
		PrintRoute(x , y +1);
	}

}

int main() {
	int x, y;

	scanf("%d %d", &x, &y);

	if (FindMaze(x, y))
		printf("EXIST\n");
	else
		printf("Not EXIST\n");

	PrintRoute(x, y);
}