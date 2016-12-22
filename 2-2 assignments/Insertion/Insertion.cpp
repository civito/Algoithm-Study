// 2013011703_Á¤Çö±³ 

#include<stdio.h>
#include<stdlib.h>

void InsertionSort(int *arr, int size){
	int j,i,key;
	
	for(j=1; j<size; j++){
		key = arr[j];
		i = j-1;
		while(i>=0 && arr[i] < key){
			arr[i+1] = arr[i];
			i = i-1;
		}
		arr[i+1] = key;
	}
}

int main(){
	int *A;
	int i, size; 
	A = (int*)malloc(sizeof(int) * 30000);
	
	scanf("%d", &size);
	for(i=0; i<size; i++){
		scanf("%d", &A[i]);
	} 
	
	InsertionSort(A,size);
	
	for(i=0; i<size; i++){
		printf("%d\n", A[i]);
	}
	
	return 0;	
}
