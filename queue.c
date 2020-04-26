#include <stdio.h>
#define MAX 30

void cenque(int n, int q[], int *front, int *rear);
int cdeque(int q[], int *front, int *rear);
void printq(int q[], int *front, int *rear);

int main()
{
	int q[MAX];
	int front=-1, rear=-1;
	
	cenque(4, q, &front, &rear);
	cenque(5, q, &front, &rear);
	cenque(6, q, &front, &rear);
	cdeque(q, &front, &rear);
	printq(q, &front, &rear);
	return 0;
}
 
void cenque(int n, int q[], int *front, int *rear)
{
	if( (*rear)==MAX )
		(*rear)=0;
	else
		(*rear)++;
	
	if( (*rear) == (*front) )
	{
		printf("Overflow!");
		if( (*rear)==0 )
			(*rear)=MAX;
		else
			(*rear)--;
		return;
	}
	
	q[*rear]=n;
	if( (*front)==-1 )
		(*front)=0;
}

int cdeque(int q[], int *front, int *rear)
{
	int n;
	
	if( (*rear) == (*front) == -1 )
	{
		printf("Underflow!");
		return 0;
	}
	n=q[*front];
	
	if( (*rear) == (*front) )
	{
		(*rear)=(*front)=-1;
	}
	else
	{
		if( (*front)==MAX )
			(*front)=0;
		else
			(*front)++;
	}
	
	return(n);
}

void printq(int q[], int *front, int *rear)
{
	int i=(*front);
	if((*front)!=-1)
		printf("%d ", q[i]);
	
	while(i!=(*rear))
	{
		if( i==MAX )
			i=0;
		else
			i+=1;
		printf("%d ", q[i]);
	}
}
