#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char * str, * str2;
	
	int arr [100], i =0, k;
	str = (char*)malloc(sizeof(char)*10000);
	
	
	gets(str);
	
	str2 = strtok(str," ");
	
	while(str2 != NULL){
		arr[++i] = atoi(str2);
		str2 = strtok(NULL," ");
	}
	
	for (k =1; k<i+1; k++){
	    printf("%d ",arr[k]);
	}
	
	return 0;
	
}
