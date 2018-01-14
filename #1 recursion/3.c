#include<stdio.h>
#define MAX 1000

void PrintToken(char* str) {
	if (*str == '\0');
	else {
		PrintToken(str + 1);
		printf("%c", *str);
	}
}

int main() {
	char* str[MAX];
	
	scanf("%s", str);
	
	PrintToken(str);
}
