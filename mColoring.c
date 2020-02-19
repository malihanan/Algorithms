#include<stdio.h>
#define V 4
#define M 2

	    //1  2  3  4
int G[V][V]={{0, 1, 0, 1},  //1
	     {1, 0, 1, 0},  //2
	     {0, 1, 0, 1},  //3
	     {1, 0, 1, 0}}; //4 
int x[V]={0};

void mColoring(int k);
void nextValue(int k);
void print(int x[]);
	
main(){
	mColoring(0);
}

void mColoring(int k){
	do{
		nextValue(k);
		if(x[k]==0)
			return;
		if(k==(V-1))
			print(x);
		else
			mColoring(k+1);
	}while(1);
}

void nextValue(int k){
	int j;
	do{
		x[k]=(x[k]+1)%(M+1);
		if(x[k]==0)
			return;
		for(j=0; j<k; j++){
			if(G[j][k]!=0 && x[k]==x[j])
				break;	
		}
		if(j==k)
			return;
	}while(1);
}

void print(int x[]){
	int i;
	for(i=0; i<V; i++){
		printf("%d", x[i]);
	}
	printf("\n");
}
