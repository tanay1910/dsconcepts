#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else{
		return(fib(n-1)+fib(n-2));
			}
}

void main()
{
	int x;
	x=5;
	printf("%d\n",fib(x) );
}