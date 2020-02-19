#include<stdio.h>
#define MAX 5

void quickSortAsc(int data[], int a2[], int a3[], int low, int high);
void quickSortDesc(int data[], int a2[], int a3[], int low, int high);
void swap(int a1[], int a2[], int a3[], int i, int j);
void printArray(int a[]);

main(){
	int jobID[]={1, 2, 3, 4, 5};
	int deadline[]={2, 1, 2, 1, 3};
	int profit[]={100, 19, 27, 25, 15};
	int ans[MAX]={0};
	int i=0;
	
	quickSortAsc(deadline, profit, jobID, 0, MAX-1);
	quickSortDesc(deadline, profit, jobID, 0, MAX-1);
	
	/*
	printArray(jobID);
	printArray(deadline);
	printArray(profit);
	*/
	while(i!=MAX){
		ans[i]=1;
		do{
			i++;
		}while(i!=MAX && deadline[i]==deadline[i-1]);
	}

	printf("ans: ");
	for(i=0; i<MAX; i++){
		if(ans[i]==1)
			printf("%d ", jobID[i]);
	}
	printf("\n");
}

void quickSortAsc(int data[], int a2[], int a3[], int low, int high)
{
	float pivot=data[high];
	int i, j=low;
	if(high<=low)
		return;
		
	for(i=low; i<high; i++)
	{
		if(data[i]>=pivot)
			swap(data, a2, a3,  i, j++);
	}
	swap(data, a2, a3, high, j);
	quickSortAsc(data, a2, a3, low, j-1);
	quickSortAsc(data, a2, a3, j+1, high);
}

void quickSortDesc(int data[], int a2[], int a3[], int low, int high)
{
	float pivot=data[high];
	int i, j=low;
	if(high<=low)
		return;
		
	for(i=low; i<high; i++)
	{
		if(data[i]<=pivot)
			swap(data, a2, a3,  i, j++);
	}
	swap(data, a2, a3, high, j);
	quickSortDesc(data, a2, a3, low, j-1);
	quickSortDesc(data, a2, a3, j+1, high);
}


void swap(int a1[], int a2[], int a3[], int i, int j)
{
	int temp=a1[i];
	a1[i]=a1[j];
	a1[j]=temp;
	
	temp=a2[i];
	a2[i]=a2[j];
	a2[j]=temp;
	
	temp=a3[i];
	a3[i]=a3[j];
	a3[j]=temp;
}

void printArray(int a[])
{
	int i, j;
	printf("\n*****");
	for(i=0; i<MAX; i++)
		printf("%d ", a[i]);
	printf("*****\n");
}