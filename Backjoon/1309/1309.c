#include<stdio.h>

int main(){
	int N;
	int i;
	int DP[100000];
	
	scanf("%d", &N);
	
	DP[0] = 3;
	DP[1] = 7;
	
	for(i =2; i< N; i++){
		DP[i] = 2*DP[i-1] + DP[i-2];
		DP[i] %= 9901;
	}
	
	printf("%d\n", DP[N-1]);
	
	
}
