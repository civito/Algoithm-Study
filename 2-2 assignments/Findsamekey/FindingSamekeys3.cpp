// 2013011703Á¤Çö±³ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Strtok(char * str, int * arr){
	char *tmpstr;
	int i=0;
	
	gets(str);

	tmpstr = strtok(str," ");
	while(tmpstr != NULL){
		arr[++i]= atoi(tmpstr);
		tmpstr = strtok(NULL," ");
	}
}

int FindSameKey(int * arr, int *arr2, int size1, int size2){
	int i,j, count=0, key;
	
	
	for(i=1;i<size1 +1; i++){
		 key= arr[i];
		 
		for(j=1; j<size2 +1; j++){
			if(arr2[j] == key){
				++count;
				break;
			}
		}
	}
	
	return count;
}
	


int main(void){
	int *arr, *arr2;
	char *str, *str2, *tmpstr1, *tmpstr2;
	int num1, num2, i, count;
	str = (char*)malloc(sizeof(char)*100000);
	str2 = (char*)malloc(sizeof(char)*100000);
	
	scanf("%d %d", &num1, &num2);
	arr = (int*)malloc(sizeof(int)*num1+1);
	arr2 = (int*)malloc(sizeof(int)*num2+1);
	
	getchar();
	
	Strtok(str, arr);
	Strtok(str2, arr2);
	
	count = FindSameKey(arr, arr2, num1, num2);
	
	printf("%d ", count);
	
	return 0;
	
}
