//Selection Sort
#include <stdio.h>
#define MAX 6

void selectionSort(int a[]);
void swapi(int i, int j, int a[]);
void printArray(int a[]);

int main()
{
	int sortedArray[MAX]={11, 12, 13, 14, 15, 16};
	int revSortedArray[MAX]={16, 15, 14, 13, 12, 11};
	printf("For Sorted Array: ");
	selectionSort(sortedArray);
	printArray(sortedArray);
	printf("\nFor Reverse Sorted Array:");
	selectionSort(revSortedArray);
	printArray(revSortedArray);
	return 0;
}

void selectionSort(int a[])
{
	int i, j, min, temp, comp=0, swap=0;
	for(i=0; i<(MAX-1); i++)
	{
		min=i;
		for(j=(i+1); j<MAX; j++)
		{
			printf("\nCompared %d and %d.", a[min], a[j]);
			comp++;
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			swapi(i, min, a);
			printf("\nSwapped %d and %d.", a[i], a[min]);
			swap++;
		}
	}
	printf("\nComparisons: %d, Swap: %d\n", comp, swap);
}

void swapi(int i, int j, int a[])
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
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
