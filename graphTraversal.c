//dfs-Depth First Search recursive and iterative
#include <stdio.h>
#include<stdlib.h>
#define MAX 8

void rec_dfs(int i, int mat[][MAX]);
void dfs(int mat[][MAX], int s[], int *top);
void mark(int n, int mat[][MAX]);
void reset(int mat[][MAX]);
void add_mat(int mat[][MAX]);
void print_mat(int mat[][MAX]);
void push( int n, int s[], int *top);
int pop( int s[], int *top);

int main()
{
	int mat[MAX][MAX]={0};
	int top=-1, s[30];
	add_mat(mat);
	print_mat(mat);
	printf("\nDepth first search:\n");
	dfs(mat, s, &top);
	reset(mat);
	printf("\nRecursively:\n");
	rec_dfs(0, mat);
}

void dfs(int mat[][MAX], int s[], int *top)
{
	int i=0, j;
	
	push(i, s, top);
	mark(i, mat);
	
	while((*top) != -1)
	{
		i = pop(s, top);
		printf("%d ", i);
	
		for(j=0; j<MAX; j++)
		{
			if(mat[i][j]==1)
			{
				push(j, s, top);
				mark(j, mat);
			}
		}
	}
	
}

void rec_dfs(int i, int mat[][MAX])
{
	int j;
	printf("%d ", i);
	mark(i, mat);
	for(j=0; j<MAX; j++)
	{
		if( mat[i][j]==1 )
			rec_dfs(j, mat);
	}
}
	
void mark(int n, int mat[][MAX])
{
	int i, j;
	for(i=0; i<MAX; i++)
	{
		mat[i][n]=999;
	}
}

void reset(int mat[][MAX])
{
	int i, j;
	for(i=0; i<MAX; i++)
	{
		for(j=0; j<MAX; j++)
		{
			if(mat[i][j]==999)
			{
				mat[i][j]=1;
			}
		}
	}
}
void add_mat(int mat[][MAX])
{	
	mat[0][1]=mat[0][4]=mat[1][0]=mat[1][2]=mat[1][3]=mat[2][1]=mat[3][1]=mat[3][4]=mat[3][6]=mat[3][7]=mat[4][0]=mat[4][3]=mat[4][5]=mat[5][4]=mat[5][6]=mat[6][3]=mat[6][5]=mat[7][3]=1;
}

void print_mat(int mat[][MAX])
{
	int i, j;
	printf("    ");
	for(i=0; i<MAX; i++)
	{
		printf("%3d", i);
	}
	printf("\n");
	for(i=0; i<(MAX+1); i++)
	{
		printf("___", i);
	}
	printf("\n");
	for(i=0; i<MAX; i++)
	{
		printf("%3d|", i);
		for(j=0; j<MAX; j++)
		{
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}
}

void push(int n, int s[], int *top)
{ 	
	if( (*top) >= MAX )
	{
		printf("Stack Overflow!");
		return;
	}
	s[++(*top)]=n;
}

int pop(int s[], int *top)
{
	if( (*top) < 0 )
	{
		printf("Stack Underflow!");
		return(0);
	}
	return(s[(*top)--]);
}
