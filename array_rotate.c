//Program for array rotation
//Write a function rotate(ar[], d, n) that rotates arr[] of size d by n elements.

#include <stdio.h>
#define MAX 6

void rotateRight(int arr[], int d, int n) {
	int i, j=0;
	int tempArr[n];
	for (i=d-n; i<d; i++) {
		tempArr[j++] = arr[i];
	}
	for(i=d-1; i>=n; i--){
	    arr[i] = arr[i-n];
	}
	for(i=0; i<n; i++){
	    arr[i]=tempArr[i];
	}
}

int gcd(int x, int y) {
	int temp;
	while(y) {
		temp = y;
		y = x%y;
		x = temp;
	}
	return x;
}

void rotateRightJuggling(int arr[], int d, int n) {
    n = n%d;
    if (n == 0) { return; }
	int c = gcd(d,n), i, j, temp, k;

	for(i=0; i<c; i++) {
		j=d-c+i;
		temp = arr[j];
		while(1) {
		    k = j-n;
		    if (k<0) { k+=d; }
		    if (k==d-c+i) { break; }
		    arr[j] = arr[k];
		    j=k;
		}
		arr[j] = temp;
	}
}
 
int main() 
{ 
   int arr[MAX] = {10, 20, 30, 40, 50, 60};
   int i, j;
   for (j=0; j<MAX; j++) {
       rotateRightJuggling(arr, MAX, j);
       for (i=0; i<MAX; i++){
           printf("%d ", arr[i]);
       }
       printf("\n");
   }
   return 0; 
} 
