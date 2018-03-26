//2013011703Á¤Çö 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Counting_Sort(int* A,int Asize,int rangeIP,int* start,int* end,int range)
{
   int i,j;
   int* C=(int*)malloc(sizeof(int)*rangeIP);
   for(i=0;i<rangeIP;i++){
      C[i]=0;
   }

   for(j=1;j<=Asize;j++){
      C[A[j]]=C[A[j]]+1;
   }
   
   for(i=1;i<=rangeIP;i++){
      C[i]=C[i]+C[i-1];
   }
   
   for(int i=0;i<range;i++){
      printf("%d\n",C[end[i]]-C[start[i]-1]);
   }
   
}


int main()
{
   int key,rangeIP,range,i=0;
   int* A;
   int* B;
   int* keys;
   
   scanf("%d %d %d",&key,&rangeIP,&range);
   
   A=(int*)malloc(sizeof(int)*range+1);
   B=(int*)malloc(sizeof(int)*range+1);
   keys=(int*)malloc(sizeof(int)*key+1);
   
   for(i=0;i<range;i++){
      scanf("%d %d",&A[i],&B[i]);
   }
   
   for(i=1;i<=key;i++){
      scanf("%d",&keys[i]);
   }
   
   Counting_Sort(keys,key,rangeIP,A,B,range);
   
}
