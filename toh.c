//tower of hanoi
#include<stdio.h>
#define MAX 30

void toh(int disks, int src[], char s, int dst[], char d, int aux[], char a);

int main()
{
	int disks;
	char s='s', d='d', a='a';
	int src[MAX], dst[MAX], aux[MAX];
	int stop=-1, dtop=-1, atop=-1;
	printf("Enter no. of disks:");
	scanf("%d", &disks);
	printf("\nSolution:");
	toh( disks, src, s, dst, d, aux, a);
	return(0);
}

void toh(int disks, int src[], char s, int dst[], char d, int aux[], char a)
{
	int n;
	if( disks==1)
	{
		printf("\nmove %c -> %c", s, d); 
		return;
	}
	toh(disks-1, src, s, aux, a, dst, d);
	printf("\nmove %c -> %c", s, d);
	toh(disks-1, aux, a, dst, d, src, s);
}
