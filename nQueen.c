#include<stdio.h>
#define MAX 4

int x[MAX]={0};

int placeQueen(int k, int i);
void nQueen(int k, int n);
int placeElephant(int k, int i);
void nElephant(int k, int n);
int abs(int a, int b);
void write(int x[], int n);

main(){
	printf("Possible positions for Queen:\n");
	nQueen(0, MAX);
	printf("\nPossible positions for Elephant:\n");
	nElephant(0, MAX);
}

int placeQueen(int k, int i){
	int j;
	for(j=0; j<k; j++){
		if(x[j]==i)
			return 0;
		if(abs(j,k) == abs(x[j],i))
			return 0;
	}
	return 1;
}

int placeElephant(int k, int i){
	int j;
	for(j=0; j<k; j++){
		if(x[j]==i)
			return 0;
	}
	return 1;
}

void nQueen(int k, int n){
	int i;
	for(i=0; i<n; i++){
		if(placeQueen(k, i)){
			x[k]=i;
			if(k==n-1)
				write(x, n);
			else
				nQueen(k+1, n);
		}
	}
}

void nElephant(int k, int n){
	int i;
	for(i=0; i<n; i++){
		if(placeElephant(k, i)){
			x[k]=i;
			if(k==n-1)
				write(x, n);
			else
				nElephant(k+1, n);
		}
	}
}

int abs(int a, int b){
	if((a-b)<0)
		return (b-a);
	else
		return (a-b);
}

void write(int x[], int n){
	int i;
	for(i=0; i<n; i++)
		printf("%d ", x[i]+1);
	printf("\n");
}