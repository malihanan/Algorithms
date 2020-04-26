#include <stdio.h>
#define MAX 9

void print_mat(int mat[][MAX]);
void dijkstra(int src, int mat[][MAX], int dist[]);

int main()
{
	int i, src, dist[MAX];
	for(i=0; i<MAX; i++)
	{
		dist[i]=999;
	}
	int mat[MAX][MAX]=
				{{0, 4, 0, 0, 0, 0, 0, 8, 0}, 

         {4, 0, 8, 0, 0, 0, 0, 11, 0}, 

         {0, 8, 0, 7, 0, 4, 0, 0, 2}, 

         {0, 0, 7, 0, 9, 14, 0, 0, 0}, 

         {0, 0, 0, 9, 0, 10, 0, 0, 0}, 

         {0, 0, 4, 14, 10, 0, 2, 0, 0}, 

         {0, 0, 0, 0, 0, 2, 0, 1, 6}, 

         {8, 11, 0, 0, 0, 0, 1, 0, 7}, 

         {0, 0, 2, 0, 0, 0, 6, 7, 0}};
	print_mat(mat);
	printf("\nEnter source:");
	scanf("%d", &src);
	printf("\nThe shortest distances are:\nNode Distance\n");
	dijkstra(src, mat, dist);
	for(i=0; i<MAX; i++)
	{
		printf("%4d %4d\n", i, dist[i]);
	}
}

void dijkstra(int src, int mat[][MAX], int dist[])
{
	int i, min_dist, min_i, d;
	int mark[MAX]={0};
	dist[src]=0;

	do
	{
		mark[src]=1;
		for(i=0; i<MAX; i++)
		{
			d=dist[src]+mat[src][i];
			if((d<dist[i]) && (mark[i]==0))
			{
				if(mat[src][i] != 0)
				{
					dist[i]=d;
				}
			}
		}
		min_dist=min_i=999;
	
		for(i=0; i<MAX; i++)
		{
			if( (dist[i]<min_dist) && (mark[i]==0) )
			{
				min_dist=dist[i];
				min_i=i;
			}
		}
		src=min_i;
	}
	while(src != 999);
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
