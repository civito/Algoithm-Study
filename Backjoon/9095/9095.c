#include<stdio.h>
#include<stdlib.h>


int main() {
	int num,num2, i,j;
	int arr[11];
	

	scanf("%d", &num);


	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (i = 0; i < num; i++) {
		scanf("%d", &num2);
		for (j = 4; j < num2 + 1; j++) {
			arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];
		}
		printf("%d\n", arr[num2]);
	}

	return 0;


}