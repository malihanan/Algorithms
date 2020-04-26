#include <stdio.h>
#include<stdlib.h>

struct struct_data
{
	int data;
	struct struct_data *left, *right;
};
typedef struct struct_data node;

void create(node **root);
void preorder(node *root);
void postorder(node *root);
void inorder(node *root);

int main()
{
	node *root=NULL;
	create(&root);
	printf("\nPre-order:\n");
	preorder(root);
	printf("\nPost-order:\n");
	postorder(root);
	printf("\nIn-order:\n");
	inorder(root);
	return 0;
}
 
void create(node **root)
{
	int ans;
	(*root)=(node *)malloc(sizeof(node));
	printf("\nEnter data: ");
	scanf("%d", &((*root)->data) );
	((*root)->left)=((*root)->right)=NULL;
	
	printf("\nIs there a left node of %d?: ", (*root)->data );
	scanf("%d", &ans);
	if( ans==1 )
	{
		create(&(*root)->left);
	}
	
	printf("\nIs there a right node of %d?: ", (*root)->data );
	scanf("%d", &ans);
	if( ans==1 )
	{
		create(&(*root)->right);
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

void postorder(node *root)
{
	if(root==NULL)
	{
		printf("Empty tree");
		return;
	}
	if(root->left != NULL)
	{
		postorder(root->left);
	}
	if(root->right != NULL)
	{
		postorder(root->right);
	}
	printf("%d ", root->data);
}

void inorder(node *root)
{
	if(root==NULL)
	{
		printf("Empty tree");
		return;
	}
	if(root->left != NULL)
	{
		inorder(root->left);
	}
	printf("%d ", root->data);
	if(root->right != NULL)
	{
		inorder(root->right);
	}
}

/*Input:
1 1 2 1 4 1 8 0 0 1 9 0 0 1 5 0 0 1 3 1 6 0 0 1 7 0 0
*/