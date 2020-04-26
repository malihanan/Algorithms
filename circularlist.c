//delete in circular link list
#include <stdio.h>
#include <stdlib.h>

struct struct_data
{
	int data;
	struct struct_data *next;
};
typedef struct struct_data node;

void create( node **head );
void print_list( node *head );
void delete_x( int x, node **head );

int main()
{
	node *head=NULL;
	int n;
	create(&head);
	print_list(head);
	scanf("%d", &n);
	delete_x(n, &head);
	printf("\n");
	print_list(head);
	return 0;
}

void delete_x( int x, node **head )
{
	node *temp, *temp2;
	//empty list
	if( *head == NULL )
	{
		printf("Underflow");
		return;
	}
	//only 1 node and not x
	if( (*head)->next == (*head) && (*head)->data != x)
		printf("Node not found!");
		
	//first node
	if( (*head)->data == x )
	{
		temp=(*head);
		
		if((*head)->next == (*head))
			(*head)=NULL;
		else
		{
			temp2=(*head);
			while(temp2->next != (*head))
				temp2=temp2->next;
				
			(*head)=(*head)->next;
			temp2->next=(*head);
		}
		
		free(temp);
		return;
	}
	
	temp=*head;
	while(temp->next != *head )
	{
		if(temp->next->data == x)
			break;
		temp=temp->next;
	}
	if( temp->next == *head )
	{
		printf("\nNode not found!");
		return;
	}
	temp2=temp->next;
	temp->next=temp->next->next;
	free(temp2);
}

void create( node **head )
{
	int temp_data;
	node *node1, *prev;
	scanf("%d", &temp_data );
	while( temp_data != 999 )
	{
		node1=(node *)malloc( sizeof(node) );
		node1->data=temp_data;
		node1->next=*head;
		if( *head==NULL )
			(*head)=node1;
		else
			prev->next=node1;
		
		prev=node1;
		scanf("%d", &temp_data );
	}
}

void print_list( node *head )
{
	node *temp;
	if( head==NULL )
		return;
	
	temp=head;
	do
	{
		printf("-> %d", temp->data );
		temp=temp->next;
	}
	while( temp != head );
}
