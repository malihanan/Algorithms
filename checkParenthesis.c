//Write a program to check if mathematical expression is correctly parenthesized or not.
#include <stdio.h>
#define MAX 30

char pop( char s[], int *top);
void push( char ch, char s[], int *top);
int check(char s[], int *top);

int main()
{
	int top=-1;
	char s[MAX];
	printf("Enter infix string:");
	if( check(s, &top) )
	{
		printf("Incorrect!");
	}
	else
	{
		printf("Correct!");
	}
	return 0;
}
 
int check(char s[], int *top)
{
	char c;
	while( (c=getchar()) != '#' )
	{
		if( c=='(' )
			push(c, s, top);
		
		if( c==')' )
		{
			if( (*top) == -1 )
				return 1;
			else
				pop(s, top);
		}
	}
	if( (*top) != -1 )
	{
		return 1;
	}
	return 0;
}

char pop( char s[], int *top)
{
	if( (*top < 0) || (*top >=MAX) )
	{
		printf("Error");
		return('#');
	}
	return(s[(*top)--]);
}

void push( char ch, char s[], int *top)
{ 	
	if( (*top)>= MAX )
	{
		printf("Stack Overflow!");
		return;
	}
	s[(*top)++]=ch;
}
