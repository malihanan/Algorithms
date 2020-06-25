//Bubble Sort
#include <stdio.h>
#define MAX 6

void bubbleSort(int a[]);
void printArray(int a[]);

int main()
{
	int sortedArray[MAX]={11, 12, 13, 14, 15, 16};
	int revSortedArray[MAX]={16, 15, 14, 13, 12, 11};
	printf("For Sorted Array: ");
	bubbleSort(sortedArray);
	printArray(sortedArray);
	printf("\nFor Reverse Sorted Array:");
	bubbleSort(revSortedArray);
	printArray(revSortedArray);
	return 0;
}

void bubbleSort(int a[])
{
	int pass, j, temp, comp=0, swap=0, counter=MAX;
	for(pass=0; pass<MAX-1; pass++)
	{
		for(j=1; j<counter; j++)
		{
			printf("\nCompared %d and %d.", a[j-1], a[j]);
			comp++;
			if(a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				printf("\nSwapped %d and %d.", a[j-1], a[j]);
				swap++;
			}
		}
		counter--;
	}
	printf("\nComparisons: %d, Swap: %d\n", comp, swap);
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
