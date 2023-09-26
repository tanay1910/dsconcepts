#include<stdio.h>
#include<stdlib.h>

int multiply(int m, int n)
{
	int y;

	if(m==0||n==0)
		return 0;
	if(n==1)
		return m;
	else{
		y=multiply(m,n-1);
		return(y+m);
	}
}

void main()
{
	int x;
	x=5;
	int y;
	y=2;
	printf("%d \n", (multiply(x,y)));

}