#include<stdio.h>
#include<stdlib.h>

struct Node{
	struct Node* Next;	
	int Num;
};

void InitArr(struct Node **N, int num){
	int i;
	for(i=0; i<num+1; i++){
		N[i] = (struct Node*)malloc(sizeof(struct Node*));
		N[i]->Next = NULL;
		N[i]->Num = i;
	}
}



 struct Node* Insertion(struct Node* N1, struct Node* N2){
	
	if(N1->Next = NULL){
		struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
		n2->Num = N2->Num;
		n2->Next = N2->Next;
		N1->Next = n2;
	}
	else{
	//	Insertion(N1->Next, N2);
	}
}

int main(void){
	char fin;
	int i, num;
	int num1, num2;
	
	scanf("%d", &num);
	
	struct Node* N[num];
	InitArr(N, num);
	
	while(1)
   {
    	fin=scanf("%d %d",&num1,&num2);
    //  N[num1] = Insertion(N[num1], N[num2]);
		struct Node* T1 = (struct Node*)malloc(sizeof(struct Node));
    	T1->Next = NULL;
    	T1->Num = N[num2]->Num;
    	N[num1]->Next = T1;  
    	struct Node* T2 = (struct Node*)malloc(sizeof(struct Node));
    	T2->Next = NULL;
    	T2->Num = N[num1]->Num;
    	N[num2]->Next = T2;  
    //Insertion(N[num2], N[num1]);
    	if(fin==EOF)break;
 	}
	
	printf("%d \n", N[num1]->Next->Num);
}
