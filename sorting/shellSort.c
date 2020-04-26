#include <stdio.h>

void shellSort(int data[], int length);
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
	shellSort(data, length);
	printf("Sorted data: ");
	for(i=0; i<length; i++)
		printf("%d ", data[i]);
	return 0;
}
 
void shellSort(int data[], int length)
{
	int gap=length/2;
	int i, j;
	
	while(gap>0)
	{
		for(i=0; (i+gap)<length; i++)
			if(data[i]>data[i+gap])
			{
				swap(data, i, i+gap);
				
				for(j=i; (j-gap)>=0; j-=gap)
					if(data[j]<data[j-gap])
						swap(data, j, j-gap);
					else
						break;
			}
		gap/=2;
	}
}

void swap(int data[], int a, int b)
{
	int temp=data[a];
	data[a]=data[b];
	data[b]=temp;
}
