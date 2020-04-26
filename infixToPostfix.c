//program to convert infix notation into postfix notation with brackets.
//r-rank, ip-input precedence, sp -stack precedence
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

char pop( char s[], int *top);
void push( char ch, char s[], int *top);
void convert(char s[], int *top, char polish[]);
int r(char c);
int ip(char c);
int sp(char c);

int main()
{
	int top=-1;
	char s[MAX];
	char polish[MAX]={'\0'};
	push('(', s, &top);
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
		if(	top<0 )
		{
			printf("Incorrect string!");
			exit;
		}
		while( ip(c) < sp(s[*top]) )
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
		if( ip(c) == sp(s[*top]) )
		{
			pop(s, top);
		}
		else
		{
			push(c, s, top);
		}
	}
	if( (*top)!=-1 || rank!=1 )
	{
		printf("\nInvalid");
	}
	else
	{
		printf("\nValid");
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
	 	return 3;
 	}
	 	else if( c=='^' )
	 	{
	 		return 6;
	 	}
		 	else if( c=='(' )
		 	{
		 		return 9;
		 	}
		 		else if( c==')' )
		 		{
		 			return 0;
		 		}
	else
	{
		return 7;
	}
}

int sp(char c)
{
	if( c == '+' || c == '-' )
	{
		return 2;
	}
		else if( c=='*' || c=='/' )
 	{
	 	return 4;
 	}
	 	else if( c=='^' )
	 	{
	 		return 5;
	 	}
		 	else if( c=='(' )
		 	{
		 		return 0;
		 	}
	else
	{
		return 8;
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
