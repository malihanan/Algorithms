//stack using array
#include<stdio.h>
#define MAX 10

int pop( int s[], int *top);
void push( int n, int s[], int *top);
int peep( int pos, int s[], int *top);
void print( int s[], int *top);

int main()
{
	int choice, n, top=-1, pos;
	int s[MAX];
	char ans;
	printf("1. Push 2. Pull 3. Peep\n");
	do
	{
		printf("\nEnter choice :");
		scanf("%d", &choice);
		switch(choice)
		{
			case(1):
				printf("\nEnter no. to be pushed: ");
				scanf("%d", &n);
				push(n, s, &top);
				print(s, &top);
				break;
			case(2):
				n=pop(s, &top);
				printf("Popped: %d", n);
				print(s, &top);
				break;
			case(3):
				printf("Enter position to be peeped:");
				scanf("%d", &pos);
				n=peep( pos, s, &top);
				printf("Peeped: %d", n);
				break;
			default:
				printf("Wrong choice!");
				break;
			}
		printf("\nDo u want to choose again:");
		scanf("%c", &ans);
		scanf("%c", &ans);
		printf("%c", ans);
	}
	while( ans=='Y' || ans=='y' ); 	
	return(0);
}

void print( int s[], int *top)
{ 
	int i;
	if( *top<0 || *top>=MAX )
	{
		printf("Error!");
	}
	printf("\n______________\n");
	for(i=0; i<=(*top); i++)
	{
		printf("| %d ", s[i]);
	}
	printf("\n______________\n");
}

int pop( int s[], int *top)
{
	if( *top < 0 )
	{
		printf("Underflow!");
		return(-1);
	}
	return(s[(*top)--]);
}

void push( int n, int s[], int *top)
{ 	
	if( *top>= MAX )
		printf("Overflow!");
	else
		s[++(*top)]=n;
}

int peep( int pos, int s[], int *top)
{
	if( pos<0 || pos > ((*top)+1) )
	{
		printf("Wrong position.");
		return(0);
	}
		return( s[(*top)-pos+1] ); 
}
