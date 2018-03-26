//2013011703 Á¤Çö±³ 
#include<stdio.h>
#include<stdlib.h>

int Min(int a, int b){
	return (a < b) ? a : b;
}

int Assemblyline(int F[2][100], int t[2][100], int L[2][100], int e1, int e2, int x1, int x2, int station_num){
	int i;
	F[0][1] = F[0][1] + e1;
	F[1][1] = F[1][1] + e2;
	
	for(i=2; i<station_num + 1;i++){
		if(F[0][i-1]+F[0][i] > F[1][i-1] + F[0][i]+ t[1][i-1]){
			F[0][i] = F[1][i-1] + F[0][i]+ t[1][i-1];
			L[0][i] = 2;
		}else{
			F[0][i] = F[0][i-1]+F[0][i];
			L[0][i] = 1;
		}
		
		if(F[1][i-1]+F[1][i] > F[0][i-1] + F[1][i]+ t[0][i-1]){
			F[1][i] = F[0][i-1] + F[1][i]+ t[0][i-1];
			L[1][i] = 1;
		}else{
			F[1][i] = F[1][i-1]+F[1][i];
			L[1][i] = 2;
		}
	}
	
	return Min(F[0][station_num] + x1, F[1][station_num]+x2);
}

void Route(int *route, int L[2][100], int i){
	if(i>0){
		route[i] = L[route[i+1]-1][i+1];
		i--;
		Route(route, L, i);
	}
	
}


int main(void){
	int F[2][100], L[2][100], t[2][100] = {0};
	int route[100] = {0};
	int station_num, e1, e2, x1, x2, i, j;
	
	scanf("%d", &station_num);
	scanf("%d %d", &e1, &e2);
	scanf("%d %d", &x1, &x2);
	
	for(i=1; i<station_num +1; i++){
		scanf("%d",&F[0][i]);
	}
	
	for(i=1; i<station_num +1; i++){
		scanf("%d",&F[1][i]);
	}
	
	for(i=1; i<station_num; i++){
		scanf("%d",&t[0][i]);
	}
	
	for(i=1; i<station_num; i++){
		scanf("%d",&t[1][i]);
	}
	
	printf("%d \n",Assemblyline(F, t, L, e1, e2, x1, x2, station_num));
	
	if(F[0][station_num] + x1 < F[1][station_num]+x2){
		route[station_num] = 1;
	}else{
		route[station_num] = 2;
	}
	Route(route, L, station_num-1);
	
	
	for(i=1; i<station_num+1;i++){
		printf("%d %d \n", route[i], i);
	}
}
