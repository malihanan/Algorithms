#include <stdio.h>
#include <stdlib.h>

struct struct_data
{
	int data;
	struct struct_data *next;
};
typedef struct struct_data node;

void insert(node **head, int n);
void print(node *head);

int main()
{
	node *head=NULL;
	insert(&head, 21);
	insert(&head, 14);
	insert(&head, 33);
	insert(&head, 18);
	insert(&head, 2);
	print(head);
	return 0;
}
 
void insert(node **head, int n)
{
	node *t=(*head);
	node *new=(node *)malloc(sizeof(node));
	new->data=n;
	new->next=NULL;
	//empty list
	if(*head == NULL)
	{
		(*head)=new;
		return;
	}	
	//first node
	if(n < (*head)->data)
	{
		new->next=(*head);
		(*head)=new;
		return;
	}
	
	while(t->next != NULL)
	{
		if(t->next->data > n)
			break;
		t=t->next;
	}
	new->next=t->next;
	t->next=new;
}

void print(node *head)
{
	if(head==NULL)
		return;

	printf("-> %d ", head->data);
	print(head->next);
}
