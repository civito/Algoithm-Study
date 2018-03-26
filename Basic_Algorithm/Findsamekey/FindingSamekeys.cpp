// 2013011703Á¤Çö±³ 

#include<stdio.h>
#include<stdlib.h>

int FindMaxkey(int * arr, int size){
	int i, key, largest=0;
	
	for(i=1; i<size+1;i++){
		if(arr[i]>largest){
			largest = arr[i];
		}
	}
	
	
	return largest;
}

int Counting(int * arr, int *arr2, int size1, int size2){
	int i,j, count=0, key, num;
	int* tmparr;
	i = FindMaxkey(arr, size1);
	j = FindMaxkey(arr2, size2);
	
	if(i < j){
		tmparr = (int*)malloc(sizeof(int)*j+1);
		num = j;
	}
	else{
		tmparr = (int*)malloc(sizeof(int)*i+1);
		num = i;
	}
	
	for(i =0; i<num+1; i++){
		tmparr[i] = 0;
	}
	
	for(i = 1; i<size1+1; i++){
		tmparr[arr[i]] += 1;
	}
	
	for(i = 1; i<size2+1; i++){
		if(tmparr[arr2[i]] != 0)
		++count;
	}
	
	return count;
}

int main(void){
	int *arr, *arr2;
	int num1, num2, i, count;
	
	scanf("%d %d", &num1, &num2);
	arr = (int*)malloc(sizeof(int)*num1+1);
	arr2 = (int*)malloc(sizeof(int)*num2+1);
	
	for(i=1; i<num1+1;i++){
		scanf("%d", &arr[i]);
	}
	
	for(i=1; i<num2+1;i++){
		scanf("%d", &arr2[i]);
	}
	
	
    count = Counting(arr, arr2, num1, num2);
	
	printf("%d ", count);
	
	return 0;
	
}
