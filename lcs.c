//finding longest common subsequence
#include<stdio.h>
#define DIAGONAL 10
#define TOP 20
#define LEFT 30

void print(int b[][100], char x[], int i, int j);

int main(){
	int m, n, i, j;
	char x[100], y[100];
	int c[100][100], b[100][100];
	printf("Enter string: ");
	scanf("%s", x);
	printf("Enter string: ");
	scanf("%s", y);
	m=strlen(x);
	n=strlen(y);
	for(i=0; i<=m; i++){
		b[i][0]=0;
		c[i][0]=0;
	}
	for(j=0; j<=n; j++){
		b[0][j]=0;
		c[0][j]=0;
	}
	for(i=1; i<=m; i++){
		for(j=1; j<=n; j++){
			if(x[i-1]==y[j-1]){
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=DIAGONAL;
			}
			else if(c[i-1][j]>c[i][j-1]){
				c[i][j]=c[i-1][j];
				b[i][j]=TOP;
			}
			else{
				c[i][j]=c[i][j-1];
				b[i][j]=LEFT;
			}
		}
	}
	/*
	printf("\n");
	for(i=0; i<=m; i++){
		for(j=0; j<=n; j++)
			printf("%4d", c[i][j]);
		printf("\n");
	}
	printf("\n");
	printf("\n");
	
	for(i=0; i<=m; i++){
		for(j=0; j<=n; j++)
			printf("%4d", b[i][j]);
		printf("\n");
	}*/
	printf("Longest common subsequence is: ");
	print(b, x, m, n);
	printf("\n");
	return 0;
}

void print(int b[][100], char x[], int i, int j)
{
	if(i==0 || j==0)
		return;
	if(b[i][j]==DIAGONAL){
		print(b, x, i-1, j-1);
		printf("%c", x[i-1]);
	}
	else if(b[i][j]==TOP){
		print(b, x, i-1, j);
	}
	else{
		print(b, x, i, j-1);
	}
}
