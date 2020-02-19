#include<stdio.h>
#include<math.h>
#define MAX 100

void quickSort(int data[], int low, int high);
void swap(int data[], int a, int b);
void format(int data[], int l);
void printArray(int a[], int l);
int optimize(int data[], int l);

int main(){
    int i, j, t, k, a[MAX], ans;
    scanf("%d", &t);
    for(i=1; i<=t; i++){
        scanf("%d", &k);
        for(j=0; j<k; j++){
            scanf("%d", &a[j]);
        }
		quickSort(a, 0, k-1);
		printArray(a, k);
		format(a, k);
		printArray(a, k);
		ans=optimize(a, k);
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}

void format(int data[], int l){
	int i, half=l/2, k=0;
	int temp[MAX];
	if(l%2==0)

		for(i=0; i<half; i++){
			temp[i]=data[k];
			temp[half+i]=data[k+1];
			k+=2;
		}
	else
		for(i=0; i<=half; i++){
			temp[i]=data[k];
			temp[half+i+1]=data[k+1];
			k+=2;
		}
	for(i=0; i<l; i++)
		data[i]=temp[i];
}

int optimize(int data[], int l){
	int half=l/2, i, j=0, ans=0;
	for(i=0; i<half; i++)
		ans+=pow((data[i]-i), 2);
	if(l%2!=0)
		half++;
	for(i=(l-1); i>=half; i--)
		ans+=pow((data[i]-(j++)), 2);
	return ans;
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

void printArray(int a[], int l)
{
	int i, j;
	printf("\n*****");
	for(i=0; i<l; i++)
	{
		printf("%d ", a[i]);
	}
	printf("*****\n");
}