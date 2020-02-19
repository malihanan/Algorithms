#include<stdio.h>
#include<stdlib.h>
#define MAX 5

main()
{
	int cents[MAX]={100, 25, 10, 5, 1};  //sorted
	int count[MAX]={0};
	int amt, i, flag=0;
	printf("Enter amount: ");
	scanf("%d", &amt);
	for(i=0; amt!=0; i++)
	{
		count[i]=amt/cents[i];
		amt-=(count[i]*cents[i]);
	}
	for(i=0; i<MAX; i++)
		printf("%d: %d, ", cents[i], count[i]);
}
