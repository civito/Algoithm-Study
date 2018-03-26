#include<stdio.h>
#include<stdlib.h>

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))   
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))  

int **arr;

int Max(int N){
	int DP[3] = {0,};
	int i;
	int t1,t2,t3;
	
	for(i = 0; i< N; i++){
		if(i == 0){
			DP[0] = arr[i][0];
			DP[1] = arr[i][1];
			DP[2] = arr[i][2];
		}else{
			t1 = MAX(DP[0],DP[1])+arr[i][0];
			t2 = MAX(DP[2],MAX(DP[0],DP[1]))+arr[i][1];
			t3 = MAX(DP[1],DP[2])+arr[i][2];
			DP[0] = t1;
			DP[1] = t2;
			DP[2] = t3;
		}
	}
	return MAX(DP[2],MAX(DP[0],DP[1]));
}

int Min(int N){
	int DP[3] = {0,};
	int i;
	int t1,t2,t3;
	
	for(i = 0; i< N; i++){
		if(i == 0){
			DP[0] = arr[i][0];
			DP[1] = arr[i][1];
			DP[2] = arr[i][2];
		}else{
			t1 = MIN(DP[0],DP[1])+arr[i][0];
			t2 = MIN(DP[2],MIN(DP[0],DP[1]))+arr[i][1];
			t3 = MIN(DP[1],DP[2])+arr[i][2];
			DP[0] = t1;
			DP[1] = t2;
			DP[2] = t3;
		}
	}
	return MIN(DP[2],MIN(DP[0],DP[1]));
	
}

int main(){
	int N;
	int i, j;
	
	scanf("%d", &N);
	arr = (int **)malloc(sizeof(int*) * N);
	for(i = 0; i< N; i++){
		arr[i] = (int *)malloc(sizeof(int) * 3);
	}
	
	for(i = 0; i< N; i++){
		scanf("%d %d %d", &arr[i][0],&arr[i][1],&arr[i][2]);
	}
	
	printf("%d %d",Max(N), Min(N));
		
	
}
