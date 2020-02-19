#include<stdio.h>
#include<math.h>
int c=0;

int multiply(int a, int b, int n){
	int w, x, y, z, r, m, p, q, ans;
	
	if(n==1){
		c++;
		return a*b;
	}
	else{
		m=(int)pow(10,(n/2));
		x=a%m;
		w=a/m;
		z=b%m;
		y=b/m;
		p = multiply(w, y, n/2);
		q = multiply(x, z, n/2);
		r = multiply(w+x, y+z, n/2);
		return( p*(int)pow(10,n) + (r-p-q)*m + q); //use shift here
	}
}

main(){
	int a, b, t1, t2, m1=1, m2=1, l=-1;
	printf("Enter first number: ");
	scanf("%d", &a);	
	printf("Enter second number: ");
	scanf("%d", &b);
	t1=a;
	t2=b;
	while(m1!=0 || m2!=0){
		m1=t1%10;
		t1/=10;
		m2=t2%10;
		t2/=10;
		l++;
	}
	printf("Product is: %d \n", multiply(a, b, l));
	printf("No. of multiplications: %d \n", c);
	printf("a*b = %d", );
}
