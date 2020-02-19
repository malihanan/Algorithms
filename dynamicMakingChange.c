//making change using dynamic programming

#include<stdio.h>
#define MAX 3
#define a 8

void makingChange(int c[], int sol[][a+1]);
void select(int sol[][a+1], int ans[], int w[]);
void printMat(int arr[][a+1]);
void printArray(int arr[], int item[]);

int main(){
	int coins[]={1, 4, 6};
	int ans[MAX]={0};
	int solution[MAX+1][a+1];
	makingChange(coins, solution);
	printMat(solution);
	select(solution, ans, coins);
	printf("\nNumber of coins:~ \n");
	printArray(ans, coins);
	printf("\n");
	return 0;
}

void makingChange(int c[], int sol[][a+1]){
	
	int i, ti, j;
	for(i=0; i<=MAX; i++)
		sol[i][0]=0;
	for(j=1; j<=a; j++)
		sol[0][j]=999;
	for(i=1; i<=MAX; i++){
		for(j=1; j<=a; j++){
			ti=i-1;
			if(c[ti]>j)
				sol[i][j]=sol[i-1][j];
			else if(sol[i-1][j]<(sol[i][j-c[ti]])+1)
				sol[i][j]=sol[i-1][j];
			else
				sol[i][j]=sol[i][j-c[ti]]+1;
		}
	}
}

void select(int sol[][a+1], int ans[], int w[]){
	int i, j=a;
	for(i=MAX; i>0; i--){
		while(sol[i][j]<sol[i-1][j]){
			ans[i-1]+=1;
			j=j-w[i-1];
		}
	}
}

void printMat(int arr[][a+1]){
	int i, j, k;
	for(k=0; k<=a+1; k++)
		printf("----+");
	printf("\n");
	printf("    |");
	for(i=0; i<=a; i++)
		printf("%3d |", i);
	printf("\n");
	for(k=0; k<=a+1; k++)
		printf("----+");
	printf("\n");
	for(i=0; i<=MAX; i++){
		printf("%4d|", i);
		for(j=0; j<=a; j++)
			printf("%3d |", arr[i][j]);
		printf("\n");
	}
	for(k=0; k<=a+1; k++)
		printf("----+");
	printf("\n");
}

void printArray(int arr[], int item[]){
	int i;
	for(i=0; i<MAX; i++)
		printf("%d: %d\n",item[i], arr[i]);
}
