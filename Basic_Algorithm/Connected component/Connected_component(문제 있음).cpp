#include<stdio.h>
#include<stdlib.h>

typedef struct Node* PtrToNode;
typedef struct Node* list;

struct Node{
	PtrToNode Next;
	int Num;
};

struct Table{
	int capacity;
	struct Node** list;
};

int component = 0;

struct Node* Make_New(void){
	
	struct Node* N = (struct Node*)malloc(sizeof(struct Node));
	N->Next = NULL;
	
	return N;
}

struct Table* Make_Table(int num){
	
	struct Table* Table = (struct Table*)malloc(sizeof(struct Table));
	Table->capacity = num;
	Table->list = (struct Node**)malloc(sizeof(struct Node*)*(Table->capacity+1));
	
	return Table;
}

void Init_Table(struct Table* T, int num){
	int i;
	
	for(i=0; i< num+1; i++){	
	
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node)*40);
		temp->Next = NULL;
		temp->Num = 0;
		T->list[i] = temp;
	}
}

void Insertion(struct Node* N1, struct Node* N2){
	
	if(N1->Next = NULL){
		struct Node* n2 = Make_New();
		n2->Num = N2->Num;
		N1->Next = n2;
		
	}
	else{
		//Insertion(N1->Next, N2);
	}
}

int main(void){
	int num, num1, num2;
	int fin,i;
	int *C;
	struct Table* T;
	
	scanf("%d", &num);
	
	C = (int*)malloc(sizeof(int)*num+1);
	C = {0};
	
	T = Make_Table(num);
	Init_Table(T, num);
	
	while(1)
   {
      fin=scanf("%d %d",&num1,&num2);
      Insertion(T->list[num1], T->list[num2]);
      Insertion(T->list[num2], T->list[num1]);
      if(fin==EOF)break;
   }

   //printf("%d %d\n", T->list[1]->Num, T->list[1]->Next->Num);
	
	
}
