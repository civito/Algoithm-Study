#include<stdio.h>

#define UP 0
#define LEFT 1
#define START 2

int mat[4][4] = {{1, 2, 3, 4},
				 {5, 6, 7, 8},
				 {9, 1, 2, 3},
				 {4, 5, 6, 7},
				};
				
int DIR[4][4] = {0,};

void PrintRoute(int i, int j){
	if(DIR[i][j] == START);
		
	else{
		if(DIR[i][j] == LEFT)
			PrintRoute(i,j-1);
		else
			PrintRoute(i-1,j);
	}
	
	printf("[%d , %d] \n", i, j);
}

int main(){
	int DP[4][4] = {0,};
	int i, j;
	
	for(i = 0; i< 4; i++){
		for(j = 0; j < 4; j ++){
			if(i == 0 && j == 0){
				DP[i][j] = mat[i][j];
				DIR[i][j] = START;
			}
			else if(i == 0){
				DP[i][j] = DP[i][j-1] + mat[i][j];
				DIR[i][j] = LEFT;
			}
			else if(j == 0){
				DP[i][j] = DP[i-1][j] + mat[i][j];
				DIR[i][j] = UP;
			}
			else{
				if(DP[i-1][j] < DP[i][j-1]){
					DP[i][j] = DP[i-1][j] + mat[i][j];
					DIR[i][j] = UP;
				}
				else{
					DP[i][j] = DP[i][j-1] + mat[i][j];
					DIR[i][j] = LEFT;
				}
			}
		}
	}
	
	PrintRoute(3,3);
	
	/*i = 3;
	j = 3;
	while(DIR[i][j] != START){
		printf("[%d , %d] \n", i, j);
		if(DIR[i][j] == LEFT)
			j--;
		else
			i--;
	}
	printf("[%d , %d] \n", i, j);
	*/
	
}
