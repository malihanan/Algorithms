#include <stdio.h>
#include<stdlib.h>

struct struct_data
{
	int data;
	struct struct_data *left, *right;
};
typedef struct struct_data node;

void insert(int n, node **root);
void preorder(node *root);

int main()
{
	node *root=NULL;
	insert(40, &root);
	insert(10, &root);
	insert(20, &root);
	insert(5, &root);
	insert(4, &root);
	preorder(root);
	return 0;
}

void insert(int n, node **root)
{
	node *newptr, *temp;
	newptr=(node *)malloc(sizeof(node));
	newptr->data=n;
	newptr->left=NULL;
	newptr->right=NULL;
	
	if((*root)==NULL)
	{
		(*root)=newptr;
		return;
	}
	temp=(*root);
	
	while(1)
	{
		if( n < (temp->data) )
		{
			if( temp->left == NULL )
			{
				temp->left=newptr;
				return;
			}
			temp=temp->left;
		}
		else
		{
			if( temp->right == NULL )
			{
				temp->right=newptr;
				return;
			}
			temp=temp->right;
		}
	}
}

void preorder(node *root)
{
	if(root==NULL)
	{
		printf("Empty tree");
		return;
	}
	printf("%d ", root->data);
	if(root->left != NULL)
	{
		preorder(root->left);
	}
	if(root->right != NULL)
	{
		preorder(root->right);
	}
}
