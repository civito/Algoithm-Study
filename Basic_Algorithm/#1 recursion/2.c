#include<stdio.h>
#define MAX 1000

void PrintToken(char* str) {
	if (*str == '\0');
	else {
		printf("%c", *str);
		PrintToken(str + 1);
	}
}

int main() {
	char* str[MAX];

	scanf("%s", str);

	PrintToken(str);

}