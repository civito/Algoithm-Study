//2013011703 Á¤Çö±³  

#include<stdio.h>
#include<stdlib.h>

void Nodeswap(node* a, node* b){
	node tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

void MinHeapify(node* Q,int i, int length){
	int smallest;
	if((2*i <= length) && (Q[2*i].freq < Q[i].freq)){
		smallest = 2*i;
	}
	else{
		smallest = i;
	}
	
	if((2*i+1 <= size) && (Q[2*i+1].freq > Q[smallest].freq)){
		smallest = 2*i+1;
	}
	
	if(smallest != i){
		swap(Q[i], Q[smallest]);
		MinHeapify(Q, smallest, size);
	}
}
	

void BuildHeap(node* Q, int length){
	int i;
	
	for(i = (length/2) ; i > 0; i--){
		MinHeapify(Q,i,length);
	}
}

void Heapsort(int *A, int size){
	int i;
	BuildHeap(A, size);
	for(i=size; i>1; i--){
		swap(&A[1], &A[i]);
		MaxHeapify(A,1,i-1);
	}
}


node Extract_min(node* Q, int length){
	node min;
	
	min = Q[1];
	Q[1] = Q[length];
	MinHeapify(Q,1,length-1);
	
	return min;
}


int main(void){
	int *arr; 
	arr=(int*)malloc(sizeof(int) * 100000);
	int i, size, key;
	
	scanf("%d %d", &size, &key);
	
	for(i=1; i<size+1; i++){
			scanf("%d", &arr[i]);
	}
	
	 BuildHeap(arr, size);
	
	
	for(i=0; i < key; i++){
		printf("%d ", arr[size - i]);
	}
	
	printf("\n");
	
	for(i= key; i < size; i++){
		printf("%d ", arr[size - i]);
	}
	
	
}
