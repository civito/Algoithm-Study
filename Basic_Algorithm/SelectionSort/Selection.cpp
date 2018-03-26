// 2013011703_Á¤Çö±³

#include<stdio.h>
#include<stdlib.h>



void selectionSort(int *arr, const int n, int count)
{
   int i, j, u,indexMin, temp; 
   int z=count;
   
   for (i = 0; i < z; i++)
   {
      indexMin = i;
      for (j = i + 1; j < n; j++)
      {
         if (arr[j] < arr[indexMin])
         {
            indexMin = j;
         }
      }
      temp = arr[indexMin];
      arr[indexMin] = arr[i];
      arr[i] = temp;
      count--;
      if (count == 0)
         break;

   }
   for (u = 0; u < n; u++)
      printf("%d\n", arr[u]);

}

int main()
{
   int arr[30000];
   int i=0, num=0, size=0;
   
   scanf("%d %d", &size, &num);
   for (i = 0; i < size; i++)
   {
      scanf("%d", &arr[i]);
   }

   selectionSort(arr, size, num);
      
   return 0;

}
