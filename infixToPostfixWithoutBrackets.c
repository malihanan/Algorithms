//program to convert infix notation into postfix notation with brackets.
//r-rank, ip-precedence
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

char pop( char s[], int *top);
void push( char ch, char s[], int *top);
void convert(char s[], int *top, char polish[]);
int r(char c);
int ip(char c);

int main()
{
	int top=0;
	char s[MAX];
	s[top]='#';
	char polish[MAX]={'\0'};
	printf("Enter infix string:");
	convert(s, &top, polish);
	printf("\nPostfix string: %s", polish);
	return 0;
}

void convert(char s[], int *top, char polish[])
{
	int i=0, rank=0;
	char c, temp;
	while( (c=getchar()) != '#' )
	{
		while( ip(c) <= ip(s[*top]) )
		{
			temp=pop(s, top);
			polish[i++]=temp;
			rank+=r(temp);
			if( rank<1 )
			{
				printf("Invalid String");
				exit;
			}
		}
		push(c, s, top);
	}
	while( s[*top] != '#' )
	{
		temp=pop(s, top);
		polish[i++]=temp;
		rank+=r(temp);
		if( rank<1 )
		{
			printf("Invalid String");
			exit;
		}
	}
	if( rank==1 )
	{
		printf("\nValid.");
	}
	else
	{
		printf("\nInvalid");
	}
}

int r(char c)
{
	if( c=='+' || c=='-' || c=='*' || c=='/' || c=='^' )
	{
		return -1;
	}
	return 1;
}

int ip(char c)
{
	if( c == '+' || c == '-' )
	{
		return 1;
	}
		else if( c=='*' || c=='/' )
 	{
	 	return 2;
 	}
	 	else if( c=='^' )
	 	{
	 		return 3;
	 	}
	 		else if( c=='#' )
	 		{
	 			return 0;
	 		}
	else
	{
		return 4;
	}
}

char pop( char s[], int *top)
{
	char ch;
	if( (*top < 0) || (*top >=MAX) )
	{
		printf("Error");
	}
	ch=s[*top];
	*top-=1;
	return(ch);
}

void push( char ch, char s[], int *top)
{ 	
	if( (*top)>= MAX )
	{
		printf("Stack Overflow!");
		return;
	}
	(*top)+=1;
	s[*top]=ch;
}
