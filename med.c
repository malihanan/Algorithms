#include<stdio.h>
#define MAX 100
#define NOCHANGE 1
#define ADD 2
#define DELETE 3
#define REPLACE 4

void med(int m, int n, int c[][MAX], int b[][MAX], char x[], char y[]);
void print(int b[][MAX], char x[], char y[], int i, int j);
int acceptString(char x[]);
void printMed(int m, int n, int c[][MAX], char x[], char y[]);
void printAction(int m, int n, int b[][MAX], char x[], char y[]);

int main(){
	int m, n, i, j;
	char x[MAX], y[MAX];
	int c[MAX][MAX], b[MAX][MAX];
	m=acceptString(x);
	n=acceptString(y);
	med(m, n, c, b, x, y); 
	printMed(m, n, c, x, y);
	printAction(m, n, b, x, y);
	printf("Perform following actions:\n");
	print(b, x, y, m, n);
	return 0;
}

void print(int b[][MAX], char x[], char y[], int i, int j)
{
	if(i==0 && j==0)
		return;
	
	if(b[i][j]==4){
		print(b, x, y, i-1, j-1);
		printf("replace %c with %c at position %d\n", x[i-1], y[j-1], i);
	}
	else if(b[i][j]==3){
		print(b, x, y, i-1, j);
		printf("delete %c at position %d\n", x[i-1], i);
	}
	else if(b[i][j]==2){
		print(b, x, y, i, j-1);
		printf("insert %c after position %d\n", y[j-1], i);
	}
	else{
		print(b, x, y, i-1, j-1);
	}
}

void med(int m, int n, int c[][MAX], int b[][MAX], char x[], char y[]){
	int i, j;
	c[0][0]=0;
	b[0][0]=1;
	for(i=1; i<=m; i++){
		b[i][0]=DELETE;
		c[i][0]=i;
	}
	for(j=1; j<=n; j++){
		b[0][j]=ADD;
		c[0][j]=j;
	}
	for(i=1; i<=m; i++){
		for(j=1; j<=n; j++){
			if(x[i-1]==y[j-1]){
				c[i][j]=c[i-1][j-1];
				b[i][j]=NOCHANGE;
			}
			else if(c[i-1][j-1]+2 <= c[i-1][j]+1){
				if(c[i-1][j-1]+2 <= c[i][j-1]+1){
					c[i][j]=c[i-1][j-1]+2;
					b[i][j]=REPLACE;
				}
				else{
					c[i][j]=c[i][j-1]+1;
					b[i][j]=ADD;
				}
			}
			else{
				if(c[i-1][j]+1 <= c[i][j-1]+1){
					c[i][j]=c[i-1][j]+1;
					b[i][j]=DELETE;
				}
				else{
					c[i][j]=c[i][j-1]+1;
					b[i][j]=ADD;
				}	
			}
		}
	}
}

int acceptString(int x[]){
	printf("Enter string: ");
	scanf("%s", x);
	return strlen(x);
}

void printMed(int m, int n, int c[][MAX], char x[], char y[]){
	int i, j;
	printf("\n        |");
	for(i=0; i<n; i++)
		printf("  %c |", y[i]);
	printf("\n   +");
	for(i=0; i<=n; i++)
		printf("----+");
	printf("\n   |");
	for(i=0; i<=m; i++){
		if(i!=0)
			printf(" %c |", x[i-1]);
		for(j=0; j<=n; j++)
			printf("%3d |", c[i][j]);
		printf("\n");
	}
	printf("\n");
}

void printAction(int m, int n, int b[][MAX], char x[], char y[]){
	int i, j;
	printf("\n          |");
	for(i=0; i<n; i++)
		printf("  %c  |", y[i]);
	printf("\n    +");
	for(i=0; i<=n; i++)
		printf("-----+", x[i]);
	printf("\n");
	for(i=0; i<=m; i++){
		if(i!=0)
			printf("  %c |", x[i-1]);
		else
			printf("    |");
		for(j=0; j<=n; j++){
			if(b[i][j]==1)
				printf(" --- |", b[i][j]);
			else if(b[i][j]==2)
				printf(" add |", b[i][j]);
			else if(b[i][j]==3)
				printf(" del |", b[i][j]);
			else
				printf(" rpl |", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
