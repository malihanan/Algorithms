//finding longest increasing subsequence
#include<stdio.h>
#define MAX 100

void print(int x[], int c[], int n, int max);
int max(int c[], int n);

int main(){
	int n, i, j, m;
	int x[MAX], c[MAX];
	printf("Enter length of first string: ");
	scanf("%d", &n);
//	int x[n], c[n+1];
	printf("Enter string: ");
	getchar();
	for(i=0; i<n; i++)
		x[i]=getchar()-'0';
	getchar();
	c[0]=0;	c[1]=1;
	for(i=2; i<=n; i++){
		c[i]=1;
		for(j=0; j<(i-1); j++)
			if(x[i-1]>x[j])
				if(c[j+1]+1 > c[i])
					c[i]=c[j+1]+1;
	}
	m=max(c, n);
	printf("\nLength of longest increasing subsequence: %d", m);
	printf("\nSequence: ");
	print(x, c, n, m);
	printf("\n");
	return 0;
}

int max(int c[], int n){
	int i, max=c[1];
	for(i=2; i<=n; i++)
		max=((c[i]>max)?c[i]:max);
	return max;
}

void print(int x[], int c[], int n, int max)
{
	int i;
	if(max==0)
		return;
	for(i=1; i<=n; i++)
		if(c[i]==max){
			print(x, c, i, max-1);
			printf("%d", x[i-1]);
			return;
		}
}