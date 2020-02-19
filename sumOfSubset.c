#include<stdio.h>
#define MAX 2

int w[MAX]={9, 19};
int x[MAX]={0};
int m=27;

void sumOfSubset(int s, int k, int r);
int add(int a[]);
void quickSort(int data[], int low, int high);
void swap(int data[], int a, int b);
void print(int a[]);

main(){
	int s;
	quickSort(w, 0, MAX-1);
	sumOfSubset(0, 0, add(w));
}

void sumOfSubset(int s, int k, int r){
	int i;
	x[k]=1;
	if(s+w[k] == m){
		for(i=k+1; i<MAX; i++)
			x[i]=0;
		print(x);
	}
	else if(s+w[k]+w[k+1] <= m)
		sumOfSubset(s+w[k], k+1, r-w[k]);
	if(s+w[k+1]<=m && s+r-w[k]>=m){
		x[k]=0;
		sumOfSubset(s, k+1, r-w[k]);
	}
}

int add(int a[]){
	int i, sum=0;
	for(i=0; i<MAX; i++)
		sum+=a[i];
	return sum;
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

void print(int a[])
{
	int i;
	for(i=0; i<MAX; i++)
		printf("%d ", a[i]);
	printf("\n");
}
