#include<stdio.h>
#define MAX 6

void mergeSort(int data[], int low, int high);
void merge(int data[], int low, int mid, int high);
void printArray(int a[]);

int main()
{
	int sortedArray[MAX]={11, 12, 13, 14, 15, 16};
	int revSortedArray[MAX]={16, 15, 14, 13, 12, 11};
	printf("For Sorted Array: ");
	mergeSort(sortedArray, 0, MAX-1);
	printArray(sortedArray);
	printf("\nFor Reverse Sorted Array:");
	mergeSort(revSortedArray, 0, MAX-1);
	printArray(revSortedArray);
	return 0;
}

void mergeSort(int data[], int low, int high)
{
	int mid=(low+high)/2;
	if(low>=high)
		return;
	mergeSort(data, low, mid);
	mergeSort(data, mid+1, high);
	merge(data, low, mid, high);
}

void merge(int data[], int low, int mid, int high)
{
	int l=mid-low+1, r=high-mid;
	int left[l], right[r];
	int i=0, j=0, k;
	
	for(k=low; k<=mid; k++)
		left[i++]=data[k];
		
	for(k=mid+1; k<=high; k++)
		right[j++]=data[k];

	i=j=0;
	k=low;
	while(i<l && j<r)
	{
		if(left[i]<=right[j])
			data[k++]=left[i++];
		else
			data[k++]=right[j++];
	}
	while(i<l)
		data[k++]=left[i++];
	while(j<r)
		data[k++]=right[j++];
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
