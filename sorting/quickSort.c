#include<stdio.h>
#define MAX 6

void quickSort(int data[], int low, int high);
void swap(int data[], int a, int b);
void printArray(int a[]);

int main()
{
	int sortedArray[MAX]={11, 12, 13, 14, 15, 16};
	int revSortedArray[MAX]={16, 15, 14, 13, 12, 11};
	printf("For Sorted Array: ");
	quickSort(sortedArray, 0, MAX-1);
	printArray(sortedArray);
	printf("\nFor Reverse Sorted Array:");
	quickSort(revSortedArray, 0, MAX-1);
	printArray(revSortedArray);
	return 0;
}

void quickSort(int data[], int low, int high)
{
	float pivot=data[high];
	int i, j=low;
	if(high<=low)
		return;
		
	for(i=low; i<high; i++)
	{
		if(data[i]<=pivot)
			swap(data, i, j++);
	}
	swap(data, high, j);
	quickSort(data, low, j-1);
	quickSort(data, j+1, high);
}

void swap(int data[], int a, int b)
{
	int temp=data[a];
	data[a]=data[b];
	data[b]=temp;
}

void printArray(int a[])
{
	int i, j;
	printf("\n*****");
	for(i=0; i<MAX; i++)
	{
		printf("%d ", a[i]);
	}
	printf("*****\n");
}
