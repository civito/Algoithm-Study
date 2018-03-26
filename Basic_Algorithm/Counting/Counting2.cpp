// 2013011703 Á¤Çö±³ 
#include<stdio.h>
#include<stdlib.h>

void Counting(int* A, int* B, int* C, int rangeIP, int range){
	int i;
	
	for(i=0; i<rangeIP+1; i++){
		C[i] = C[i] + C[i-1];
	}
	
	for(i=1; i<range+1; i++){
		if(((C[B[i]-1]) != C[B[i]]) || (C[A[i]-1]) != C[A[i]]){
			printf("%d\n", C[B[i]]-C[A[i]]+1);
		}
		else{
			printf("%d\n", C[B[i]]-C[A[i]]);
		}
	}	
}


int main(void){
	int key, rangeIP, range, i;
	int* A,* B,* C;
	int num1, num2, num3;	
	scanf("%d %d %d", &key, &rangeIP, &range);
	A = (int*)malloc(sizeof(int)*range+1);
	B = (int*)malloc(sizeof(int)*range+1);
	C = (int*)malloc(sizeof(int)*rangeIP+1);
	for(i=0; i<rangeIP+1; i++){
	  C[i] = 0;
	}
	for(i=1; i<range+1; i++){
		scanf("%d %d", &num1, &num2);
		A[i]=num1;
		B[i]=num2;
	}
	for(i=0; i<key; i++){
		scanf("%d", &num3);
		C[num3] += 1;
	}
	Counting(A,B,C,rangeIP, range);
}
