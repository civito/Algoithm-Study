#include<stdio.h>
#define min(X,Y) ((X) < (Y) ? (X) : (Y))


int main(void){
	int N, i, j;
	int A[2000] = {0};
	int dp[1005];
	
	for(i=0; i<1005; i++){
		dp[i] = 1000;
	}
	
	dp[0] = 0;
		
	scanf("%d", &N);
	
	for(i=0; i < N; i++){
		scanf("%d", &A[i]);
	}
	
	
	for(i=0; i<N; i++){
		for(j=i+1 ;j <= i+A[i]; j++){	
			dp[j] = min(dp[j] ,dp[i]+1);
			//printf("dp[%d] = %d\n",j, dp[j]);
		}
	}
	if(dp[N-1] == 1000){
		dp[N-1] = -1;
	}
	printf("%d", dp[N-1]);
	
	return 0;
}
