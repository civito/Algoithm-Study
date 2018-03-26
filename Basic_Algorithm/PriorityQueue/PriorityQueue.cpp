//2013011703 Á¤Çö±³ 

#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int * b){
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void MaxHeapify(int* A,int i, int size){
	int largest;
	int l = 2*i;
	int r = 2*i+1;
	
	if((r <= size) && (A[r]>A[i])){
		largest = r;
	}
	else{
		largest = i;
	}
	
	if((l <= size) && (A[l]>A[largest])){
		largest = l;
	}
		
	if(largest != i){
		swap(&A[i], &A[largest]);
		MaxHeapify(A, largest, size);
	}
}

void Heap_Increase_key(int* A, int i, int key){
	A[i]=key;
	while((i>1) && (A[i/2] < A[i])){
		swap(&A[i], &A[i/2]);
		i = i/2;
	}
}

int Extract_Max(int *A, int size){
	int max;
	
	max = A[1];
	A[1] = A[size];
	MaxHeapify(A,1,size-1);
	
	return max;
}


int main(void){
	int *arr, *A;
	arr = (int *)malloc(sizeof(int)*100000);
	A = (int *)malloc(sizeof(int)*100000);
	char c;
	int a, exnum, num, num2;
	int i =0, count =0, lcount =0;
	
	while(1){
		c = getc(stdin);
		a = (int)c -'0';
		
		if(a == 0){
			break;
		}
		
		else if(a==1){
			scanf("%d",&num);
			Heap_Increase_key(arr, ++count, num);
		}
		
		else if(a==2){
			if(count<1){
			}
			else{
			exnum = Extract_Max(arr, count--);
			A[++lcount] = exnum;
			}
		}
		
		else if(a==3){
			scanf("%d %d",&num, &num2);
				
			if(num >count){
			}
			
			else{
				arr[num] = num2;
		    	if((num > 1) && (arr[num] > arr[num /2])){
			    	Heap_Increase_key(arr, num, num2);
		     	}
		    	else{
		    		MaxHeapify(arr, num, count);
		    	}
		   	}
			}
			
		}
		
	
	
	for(i=1; i<lcount+1; i++){
		printf("%d ", A[i]);
	}
	
	printf("\n");
	
	for(i=1; i< count+1; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}
