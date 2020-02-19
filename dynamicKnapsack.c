//0/1 knapsack using dynamic programming

#include<stdio.h>
#define MAX 5
#define c 11

void dynamicKnapsack(int w[], int p[], int sol[][c+1]);
void select(int sol[][c+1], int ans[], int w[]);
void printMat(int a[][c+1]);
void printArray(int a[], int item[]);

int main(){
	int item[] = {1, 2, 3, 4, 5};
	int weight[]={1, 2, 5, 6, 7};
	int profit[]={1, 6, 18, 22, 28};
	int ans[MAX]={0};
	int solution[MAX+1][c+1];
	dynamicKnapsack(weight, profit, solution);
	printMat(solution);
	select(solution, ans, weight);
	printf("\nSelected items: ");
	printArray(ans, item);
	printf("\n\n");
	return 0;
}

void dynamicKnapsack(int w[], int p[], int sol[][c+1]){

	int i, ti, j;
	for(i=0; i<=MAX; i++)
		sol[i][0]=0;
	for(j=0; j<=c; j++)
		sol[0][j]=0;
	for(i=1; i<=MAX; i++){
		for(j=1; j<=c; j++){
		ti=i-1;
			if(j-w[ti]<0)
				sol[i][j]=sol[i-1][j];
			else if(sol[i-1][j]>=(sol[i-1][j-w[ti]]+p[ti]))
				sol[i][j]=sol[i-1][j];
			else
				sol[i][j]=sol[i-1][j-w[ti]]+p[ti];
		}
	}
}

void select(int sol[][c+1], int ans[], int w[]){
	int i, j=c;
	for(i=MAX; i>0; i--){
		if(sol[i][j]>sol[i-1][j]){
			ans[i-1]=1;
			j=j-w[i-1];
		}
	}
}

void printMat(int a[][c+1]){
	int i, j, k;
	for(k=0; k<=c+1; k++)
		printf("----+");
	printf("\n");
	printf("    |");
	for(i=0; i<=c; i++)
		printf("%3d |", i);
	printf("\n");
	for(k=0; k<=c+1; k++)
		printf("----+");
	printf("\n");
	for(i=0; i<=MAX; i++){
		printf("%4d|", i);
		for(j=0; j<=c; j++)
			printf("%3d |", a[i][j]);
		printf("\n");
	}
	for(k=0; k<=c+1; k++)
		printf("----+");
	printf("\n");
}

void printArray(int a[], int item[]){
	int i;
	for(i=0; i<MAX; i++)
		if(a[i]==1)
			printf("%d ",item[i]);
}
