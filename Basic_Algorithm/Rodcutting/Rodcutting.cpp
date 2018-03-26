// 2013011703_Á¤Çö±³ 

#include<stdio.h>
#include<stdlib.h>

#define LOWEST -9999


void Extended_BOTTOM_UP_CUT_ROD(int *P, int *R, int *S, int length){
	int j, i, q;
	R[0]=0;
	
	for(j=1; j< length+1; j++){
		q = LOWEST;
		for(i=1; i< j+1; i++){
			if(q< P[i] + R[j-i]){
				q= P[i]+ R[j-i];
				S[j] = i;
			} 
		}
		R[j] = q;
	}
	
}

void PRINT_CUT_ROD_SOLUTION(int *P, int *R, int *S, int length){
	Extended_BOTTOM_UP_CUT_ROD(P, R, S, length);
	
	printf("%d\n", R[length]);
	
	while(length > 0){
		printf("%d ", S[length]);
		length = length - S[length];
	}
}

int main(void){
	int *P, *R, *S;
	int length, i;
	
	scanf("%d", &length);
	
	P = (int*)malloc(sizeof(int)*length+3);
	R = (int*)malloc(sizeof(int)*length+3);
	S = (int*)malloc(sizeof(int)*length+3);
	
	for(i=1; i<length+1 ; i++){
		scanf("%d", &P[i]);
	}
	
	PRINT_CUT_ROD_SOLUTION(P, R, S, length);
}

