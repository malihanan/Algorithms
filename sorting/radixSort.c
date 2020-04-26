#include <stdio.h>

void radixSort(int data[], int length);
void countSort(int data[], int length, int exp);
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
	radixSort(data, length);
	printf("Sorted data: ");
	for(i=0; i<length; i++)
		printf("%d ", data[i]);
	return 0;
}

void radixSort(int data[], int length)
{
	int max=findMax(data, length);
	int exp, i;
	for(exp=1; max/exp!=0; exp*=10)
	{
		countSort(data, length, exp);
		for(i=0; i<length; i++)
			printf("%d ", data[i]);
		printf("\n^%d\n", exp);
	}
}

void countSort(int data[], int length, int exp)
{
	int count[10];
	int temp[length], i;

	for(i=0; i<10; i++)
		count[i]=0;
	for(i=0; i<length; i++)
		count[(data[i]/exp)%10]++;
	for(i=1; i<10; i++)
		count[i]+=count[i-1];
	
	for(i=(length-1); i>=0; i--)
		temp[--(count[(data[i]/exp)%10])]=data[i];
		
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
