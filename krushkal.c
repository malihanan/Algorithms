//krushkal MST
#include<stdio.h>
#define MAX 6
#define VTX 5

struct g
{
	int src;
	int end;
	int w;
};
typedef struct g graph;

void insert(graph mst[], int j, graph g);
void mark(int c[], graph g);
void quickSort(graph data[], int low, int high);
void swap(graph data[], int a, int b);
void printGraph(graph a[], int len);

int main()
{
	int i, j=0;
	graph garr[MAX]={{1,2,5},{1,3,2},{2, 4, 2},{4, 3, 10},{1, 5, 1},{3, 5, 1}};
	graph mst[VTX-1];
	int cycle[VTX];	//to check cycle
	for(i=0; i<VTX; i++)	//initializing cycle array
		cycle[i]=(i+1);
		
	quickSort(garr, 0, (MAX-1));	//sorting graph on the basis of edge weight
	printf("Sorted graph:");
	printGraph(garr, MAX);
	
	for(i=0; i<MAX; i++)
	{		
		if(cycle[(garr[i].src)-1] != cycle[(garr[i].end)-1])	//check if cycle is there
		{
			insert(mst, j++, garr[i]);	//insert into mst
			mark(cycle, garr[i]);
			if(check(cycle)==1)
				break;
		}
	}
	printGraph(mst, VTX-1);
	
	return 0;
}

void insert(graph mst[], int j, graph g)
{
	mst[j].src=g.src;
	mst[j].end=g.end;
	mst[j].w=g.w;
}

void mark(int c[], graph g)
{
	int i, min=c[g.src-1], max=c[g.end-1];
	if(min>max)
	{
		min=c[g.end-1];
		max=c[g.src-1];
	}
	
	for(i=0; i<VTX; i++)
		if(c[i]==max)
			c[i]=min;
}

int check(int c[])
{
	int i;
	for(i=0; i<VTX; i++)
		if(c[i]!=1)
			return 0; //not all same
	return 1; //all 1s
}
void quickSort(graph data[], int low, int high)
{
	graph pivot=data[high];
	int i, j=low;
	if(high<=low)
		return;
		
	for(i=low; i<high; i++)
	{
		if(data[i].w <= pivot.w)
			swap(data, i, j++);
	}
	swap(data, high, j);
	quickSort(data, low, j-1);
	quickSort(data, j+1, high);
}

void swap(graph data[], int a, int b)
{
	graph temp=data[a];
	data[a]=data[b];
	data[b]=temp;
}

void printGraph(graph a[], int len)
{
	int i, j;
	printf("\n*****\n");
	for(i=0; i<len; i++)
	{
		printf("%d %d %d\n", a[i].src, a[i].end, a[i].w);
	}
	printf("*****\n");
}
