#include<stdio.h>
 
void countSort(int data[], int length);
int findMax(int data[], int length);
int findMin(int data[], int length);

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
	countSort(data, length);
	printf("\nSorted data: ");
	for(i=0; i<length; i++)
		printf("%d ", data[i]);
	return 0;
}
 
void countSort(int data[], int length)
{
	int high=findMax(data, length);
	int low=findMin(data, length);
	int l=high-low+1, count[l];
	int temp[length], i;

	for(i=0; i<l; i++)
		count[i]=0;
	for(i=0; i<length; i++)
		count[data[i]-low]++;
	for(i=1; i<l; i++)
		count[i]+=count[i-1];
	
	for(i=(length-1); i>=0; i--)
		temp[--(count[data[i]-low])]=data[i];
		
	for(i=0; i<length; i++)
		data[i]=temp[i];
}

int findMax(int data[], int length)
{
	int i, max=data[0];
	for(i=1; i<length; i++)
		if(data[i]>max)
			max=data[i];
	return max;
}

int findMin(int data[], int length)
{
	int i, min=data[0];
	for(i=1; i<length; i++)
		if(data[i]<min)
			min=data[i];
	return min;
}
