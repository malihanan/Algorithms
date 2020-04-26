//bfs-Breadth First Search
#include <stdio.h>
#include<stdlib.h>
#define MAX 8

void bfs(int mat[][MAX], int q[], int *front, int *rear);
void mark(int n, int mat[][MAX]);
void reset(int mat[][MAX]);
void add_mat(int mat[][MAX]);
void print_mat(int mat[][MAX]);
void cenque(int n, int q[], int *front, int *rear);
int cdeque(int q[], int *front, int *rear);

int main()
{
	int mat[MAX][MAX]={0};
	int front=-1, rear=-1, q[30];
	add_mat(mat);
	print_mat(mat);
	printf("\nBreadth first search:\n");
	bfs(mat, q, &front, &rear);
	reset(mat);
}

void bfs(int mat[][MAX], int q[], int *front, int *rear)
{
	int i=0, j;
	
	printf("%d ", i);
	mark(i, mat);
	
	while( 1 )
	{
		for(j=0; j<MAX; j++)
		{
			if(mat[i][j]==1)
			{
				printf("%d ", j);
				mark(j, mat);
				cenque(j, q, front, rear);
			}
		}
		if((*front)==-1)
			return;
			
		i=cdeque(q, front, rear);
	}
}

void mark(int n, int mat[][MAX])
{
	int i, j;
	for(i=0; i<MAX; i++)
	{
		for(j=0; j<MAX; j++)
		{
			if(j==n && mat[i][j]==1)
			{
				mat[i][j]=999;
			}
		}
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

void cenque(int n, int q[], int *front, int *rear)
{
	if( (*rear)==MAX )
		(*rear)=0;
	else
		(*rear)+=1;
	
	if( (*rear) == (*front) )
	{
		printf("Overflow!");
		if( (*rear)==0 )
			(*rear)=MAX;	
		else
			(*rear)-=1;
			
		return;
	}
	
	q[*rear]=n;
	
	if( (*front)==-1 )
		(*front)=0;
}

int cdeque(int q[], int *front, int *rear)
{
	int n;
	
	if( (*front) == -1 )
	{
		printf("Underflow!");
		return 0;
	}
	n=q[*front];
	
	if( (*rear) == (*front) )
		(*rear)=(*front)=-1;
	
	else
	{
		if( (*front)==MAX )
			(*front)=0;
		else
			(*front)+=1;
	}
	return(n);
}
