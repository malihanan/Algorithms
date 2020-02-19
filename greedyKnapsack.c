//fractional
#include<stdio.h>
#define MAX 5

float greedyKnapsack(float p[], float w[], float c, float x[]);
void sort(float data[], float p[], float w[]);
void quickSort(float data[], float p[], float w[], int low, int high);
void swap(float data[], float p[], float w[], int a, int b);
void printSol(float p[], float w[], float x[]);

int main()
{
	float p[MAX]={30, 15, 25, 20, 10};
	float w[MAX]={10, 3, 15, 5, 5};
	float x[MAX]={0};
	float profit, c=20;
	
	profit=greedyKnapsack(p, w, c, x);
	
	printf("\nTotal profit: %f", profit);
}

float greedyKnapsack(float p[], float w[], float c, float x[]){
	float pbyw[MAX], profit=0;
	int i;

	for(i=0; i<MAX; i++)
		pbyw[i]=p[i]/w[i];
	
	sort(pbyw, p, w);

	for(i=0; i<MAX; i++)
	{
		if((c-w[i])>=0){
			x[i]=1;
			profit+=p[i];
		}
		else
		{
			x[i]=c/w[i];
			profit+=(x[i]*p[i]);
			break;
		}
		c=c-w[i];
	}
	printSol(p, w, x);

	return profit;
}

void sort(float data[], float p[], float w[])
{
	int low=0;
	int high=MAX-1;
	quickSort(data, p, w, low, high);
}

void quickSort(float data[], float p[], float w[], int low, int high)
{
	float pivot=data[high];
	int i, j=low;
	if(high<=low)
		return;
		
	for(i=low; i<high; i++)
	{
		if(data[i]>=pivot)
			swap(data, p, w, i, j++);
	}
	swap(data, p, w, high, j);
	quickSort(data, p, w, low, j-1);
	quickSort(data, p, w, j+1, high);
}

void swap(float data[], float p[], float w[], int a, int b)
{
	float temp=data[a];
	data[a]=data[b];
	data[b]=temp;
	
	temp=p[a];
	p[a]=p[b];
	p[b]=temp;
	
	temp=w[a];
	w[a]=w[b];
	w[b]=temp;
}

void printSol(float p[], float w[], float x[]){
	int i;
	for(i=0; i<MAX; i++){
		printf("-------+");
	}
	printf("\n");
	for(i=0; i<MAX; i++){
		printf("%6d |", i);
	}
	printf("\n");
	for(i=0; i<MAX; i++){
		printf("-------+");
	}
	printf("\n");
	for(i=0; i<MAX; i++){
		printf("%6.2f |", p[i]);
	}
	printf("\n");
	for(i=0; i<MAX; i++){
		printf("-------+");
	}
	printf("\n");
	for(i=0; i<MAX; i++){
		printf("%6.2f |", w[i]);
	}
	printf("\n");
	for(i=0; i<MAX; i++){
		printf("-------+");
	}
	printf("\n");
	for(i=0; i<MAX; i++){
		printf("%6.2f |", x[i]);
	}
	printf("\n");
	for(i=0; i<MAX; i++){
		printf("-------+");
	}
	printf("\n");
}
