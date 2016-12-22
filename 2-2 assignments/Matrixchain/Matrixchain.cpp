//2013011703_Á¤Çö±³ 
#include<stdio.h>
#include<stdlib.h>

int** Matrix_Chain_Order(int* P,int num)
{
   int i,l,q,j,k;
   int** m;
   int** s;
   m =(int**)malloc(sizeof(int*)*(num+3));
   s =(int**)malloc(sizeof(int*)*(num+3));

   for(i=0;i<=num;i++)
   {
      m[i]=(int*)malloc(sizeof(int)*(num+3));
   }
   for(i=0;i<=num;i++)
   {
      s[i]=(int*)malloc(sizeof(int)*(num+3));
   }


   for(i=1;i<=num;i++)
   {
      
      m[i][i]=0;
   }
   for(l=2;l<=num;l++)
   {
      for(i=1;i<=num-l+1;i++)
      {
         j=i+l-1;
         m[i][j]=999999;
         for(k=i;k<=j-1;k++)
         {
            q=m[i][k]+m[k+1][j]+P[i-1]*P[k]*P[j];
            if(q<m[i][j])
            {
               m[i][j]=q;
               s[i][j]=k;
            }
            
         }
      }
   }
   s[num][num]=m[1][num];
   return s;
}
void Print_Optimal(int** s,int i,int j)
{
   if(i==j)
      printf("%d",i);
      else
      {
         printf("(");
         Print_Optimal(s,i,s[i][j]);
         Print_Optimal(s,s[i][j]+1,j);
         printf(")");
      }
}

int main()
{
   int num,i;
   int* P;
   int** s;
   scanf("%d",&num);
   P=(int*)malloc(sizeof(int)*(num+1));
   for(i=0;i<num+1;i++)
   {
      scanf("%d",&P[i]);
   }
   s=Matrix_Chain_Order(P,num);
   printf("%d\n",s[num][num]);
   Print_Optimal(s,1,num);
   return 0;
}
