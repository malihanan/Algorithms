//( a|b, c, r ) pallindrome using stack using link list
#include<stdio.h>
#include<stdlib.h>
struct struct_data
{
	char ch;
	struct struct_data *next;
};
typedef struct struct_data node;

char pop( node **head, node **top );
void push( node **head, char ch, node **top );
void print( node *head );
void reset( node **head, node **top );

int main()
{
	char ch, check;
	node *head=NULL, *top=NULL;
	printf("String of form: w c wr; w=[a|b] \n");
	printf("Enter 'e' to reset.\n");
	printf("Enter # to end string.\n");
	printf("Enter string: ");
	while( (ch=getchar()) != 'c' )
	{
		if( ch=='#' )
		{
			printf("Not a palindrome!");
		}
			else if( ch=='e' )
			{
				reset(&head, &top);
				printf("\nString has been reset. Enter again.\n");
			}
				else if( ch == 'a' )
				{
					push( &head, ch, &top );
				}
					else if( ch == 'b' )
					{
						push( &head, ch, &top );
					}
		else
		{
			printf("Wrong character ignored.");
		}
	}
	
	while( (ch=getchar()) != '#' )
	{
		if( top==NULL )
		{
			printf("Not a palindrome!");
			exit(1);
		}
		check=pop(&head, &top);
		if( check != ch )
		{
			printf("Not a palindrome!");
			exit(1);
		}
	}
	if( top==NULL )
	{
		printf("Palindrome!");
	}
	else
	{
		printf("Not a palindrome!");
	}
	return(0);
}

void reset( node **head, node **top )
{
	while( (*head) != NULL )
	{
		pop(head, top);
	}
}

char pop( node **head, node **top )
{
	char ch;
	node *temp;
	if(*head == NULL )
	{
		printf("Stack Underflow!");
		return('_');
	}
	if( (*head)->next == NULL )
	{
		ch=(*top)->ch;
		free(*head);
		*head=*top=NULL;
		return(ch);
	}
	temp=*head;
	while(temp->next->next != NULL )
	{
		temp=temp->next;
	}
	ch=(*top)->ch;
	(*top)=temp;
	free(temp->next);
	(*top)->next=NULL;
	return(ch);
}

void push( node **head, char ch, node **top )
{ 
	node *node1=(node *)malloc( sizeof(node1) );
	node1->ch=ch;
	node1->next=NULL;
	if( *head==NULL )
	{
		*head=*top=node1;
	}
	else
	{
		(*top)->next=node1;
		(*top)=(*top)->next;
	}
}

char peep( node *head, int pos)
{
	int i;
	if( head==NULL )
	{
		printf("\nEmpty list!");
		return(0);
	}
	for(i=0; i<(pos-1); i++)
	{
		head=head->next;
		if( head==NULL )
		{
			printf("Wrong position!");
			return(0);
		}
	}
	return( head->ch );
}