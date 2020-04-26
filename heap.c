#include<stdio.h>

void createMaxHeap(int data[], int length);
void sortMaxHeap(int data[], int length);
int findParent(int data[], int i);
void swap(int data[], int a, int b);

int main()
{
	int i, length;
	printf("Enter array length: ");
	scanf("%d", &length);
	int data[length];
	printf("\nEnter data: ");
	for(i=0; i<length; i++)
	{
		scanf("%d", &data[i]);
		printf("%d ", data[i]);
	}
	printf("\n");
	createMaxHeap(data, length);
	printf("\nHeap data: ");
	for(i=0; i<length; i++)
		printf("%d ", data[i]);
	sortMaxHeap(data, length);
	printf("\nSorted Heap data: ");
	for(i=0; i<length; i++)
		printf("%d ", data[i]);
	return(0);
}

void createMaxHeap(int data[], int length)
{
	int i, parent, child;
	for(i=1; i<length; i++)
	{
		child=i;
		parent=findParent(data, i);
		while(data[child]>data[parent])
		{
			swap(data, parent, child);
			child=parent;
			parent=findParent(data, parent);
			if(parent==-1)
				break;
		}
	}
}

void sortMaxHeap(int data[], int length)
{
	int last;
	for(last=(length-1); last>0; last--)
	{
		swap(data, 0, last);
		createMaxHeap(data, last);
	}
}

int findParent(int data[], int i)
{
	if(i==0)
		return -1;
	else
		return((i-1)/2);
}

void swap(int data[], int a, int b)
{
	int temp=data[a];
	data[a]=data[b];
	data[b]=temp;
}

//10 42 23 74 11 65 58 94 36 99 87
