//Implement circular queue using linked list.
#include <stdio.h>
#include<stdlib.h>

struct struct_data
{
	int data;
	struct struct_data *next;
};
typedef struct struct_data node;

void print_list(node *front, node *last);
void enqueue(node **front, node **last, int n);
void dequeue(node **front, node **last);

int main()
{
	node *front=NULL, *last=NULL;
	enqueue(&front, &last, 1);
	enqueue(&front, &last, 2);
	dequeue(&front, &last);
	enqueue(&front, &last, 3);
	dequeue(&front, &last);
	enqueue(&front, &last, 4);
	enqueue(&front, &last, 5);
	print_list(front, last);
	return 0;
}
 
void enqueue(node **front, node **last, int n)
{
	node *newptr;
	newptr=(node *)malloc( sizeof(node) );
	newptr->data=n;
	newptr->next=(*front);
	if((*front)==NULL)
	{
		(*front)=(*last)=newptr;
		return;
	}
	(*last)->next=newptr;
	(*last)=newptr;
}

void dequeue(node **front, node **last)
{
	node *temp;
	if((*front)==NULL)
	{
		printf("List Empty!");
		return;
	}
	temp=(*front);
	if( (*front)==(*last) )
	{
		(*front)=(*last)=NULL;
	}
	else
	{
		(*front)=(*front)->next;
	}
	free(temp);
}

void print_list(node *front, node *last)
{
	node *temp;
	if( front==NULL )
	{
		return;
	}
	printf("-> %d", front->data );
	if( front==last )
	{
		return;
	}
	temp=front;
	do
	{
		temp=temp->next;
		printf("-> %d", temp->data );
	}
	while(temp!=last);
}
