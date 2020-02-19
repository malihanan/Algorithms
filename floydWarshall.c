//finding shortest path b/w any two nodes in a weighted directed graph

#include<stdio.h>
#define MAX 5

int main(){   
	int i, j, k;
				 //  1    2    3    4    5
	int g[][MAX]={{  0,   2, 999, 999,   6},  //1
				  {  3,   0, 999, 999,   1},  //2
				  {999,   2,   0,   3, 999},  //3
				  {  5, 999, 999,   0, 999},  //4
				  {999, 999,   8, 999,   0}}; //5

	for(k=0; k<MAX; k++){		//selecting each node as intermediatary node one by one
		for(i=0; i<MAX; i++)
			for(j=0; j<MAX; j++)
				if(i==j)
					g[i][j]=0;
				else
					if(i!=k)
						if((g[i][k]+g[k][j])<g[i][j])
							g[i][j]=g[i][k]+g[k][j];
		//printing
		for(i=0; i<MAX; i++){
			for(j=0; j<MAX; j++)
				printf("%5d",g[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}