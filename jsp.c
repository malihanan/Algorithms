#include<stdio.h>
#define N 4

void jsp(int g[][N]);
int minSum(int i, int j, int g[][N], int index[]);
int min(int x[]);
void print(int a[], int g[][N]);

main(){
	int g[][N] = {{9, 2, 7, 8},
				  {6, 4, 3, 7},
				  {5, 8, 1, 8},
				  {7, 6, 9, 4}};
	jsp(g);
}

void jsp(int g[][N]){
	int i, j, k, sum, x[N], index[N];
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			for(k=0; k<i; k++)
				if(j==index[k])
					break;
			if(k==i){
				x[j]=minSum(i, j, g, index)+g[i][j];
				for(k=0; k<i; k++)
					x[j]+=g[k][index[k]];
			}
			else
				x[j]=999;
		}
		index[i]=min(x);
	}
	print(index, g);
}

int minSum(int i, int j, int g[][N], int index[]){
	int sum=0, min, k, l, m;
	for(k=i+1; k<N; k++){
		min=999;
		for(l=0; l<N; l++){
			for(m=0; m<i; m++)
				if(l==index[m])
					break;
			if(m==i && l!=j)
				if(g[k][l]<min)
					min=g[k][l];
		}
		sum+=min;
	}
	return sum;
}

int min(int x[]){
	int i, min=0;
	for(i=1; i<N; i++)
		if(x[i]<x[min])
			min=i;
	return min;
}

void print(int a[], int g[][N]){
	int i;
	printf("\nSolution:\n");
	for(i=0; i<N; i++)
		printf("%d: %d (%d)\n", i, a[i], g[i][a[i]]);
}