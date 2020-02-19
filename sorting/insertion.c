//insertion sort
#include <stdio.h>
#define MAX 6

void insertionSort(int data[]);
void printArray(int a[]);

int main()
{
	int sortedArray[MAX]={11, 12, 13, 14, 15, 16};
	int revSortedArray[MAX]={16, 15, 14, 13, 12, 11};
	printf("For Sorted Array: ");
	insertionSort(sortedArray);
	printArray(sortedArray);
	printf("\nFor Reverse Sorted Array:");
	insertionSort(revSortedArray);
	printArray(revSortedArray);
	return 0;
}

void insertionSort(int data[])
{
	int i, j, flag, temp, comp=0, shift=0;
	for(i=1; i<MAX; i++)
	{
		flag=0;
		temp=data[i];
		for(j=i-1; j>=0; j--)
		{
			if(data[j]>temp)
			{
				printf("\nCompared %d and %d.", data[j], temp);
				comp++;
				data[j+1]=data[j];
				printf("\nShifted %d", data[j]);
				shift++;
				flag=1;
			}
			else
			{
				printf("\nCompared %d and %d.", data[j], temp);
				comp++;
				break;
			}
		}
		if(flag==1)
		{
			data[++j]=temp;
			printf("\nPut %d", temp);
			shift++;
		}
	}
	printf("\nComparisons: %d, Shift: %d\n", comp, shift);
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