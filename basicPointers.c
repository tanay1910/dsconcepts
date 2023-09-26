#include<stdio.h>
#include<stdlib.h>

void main()
{
	// char a;
	// char b;
	// printf("%p\n",&a );//printing character addresses
	// int a1 = 9,*p=&a1;
	// printf("%d",*p+1);//++ has more priority than *
	//
	//
	// Multiple pointers
	// int num = 10;
	// int *p1 = &num;
	// int **q1= &p1;
	// int ***r1 = &q1;
	// printf("%d %d %d %d",num,*p1,**q1,***r1);
	//
	//
	//Array and pointers
	// int arr[]={3,5,7,9,10};
	// printf("%p %p\n",arr,&arr[0] ); // arr[0], arr point to start of array
	// int *ptr = arr;
	// printf("%d is first ele.\n",*ptr);
	// int *ptr2 = &arr[1];
	// printf("%d is first ele.\n",*(ptr2-1));
	// int *ptr3 = &arr[1];
	// printf("%d is second ele.\n",*(ptr3));
	// for(int i = -1 ; i<4;i++)
	// {
	// 	printf("%d ",*(ptr3+i));
	// }
	//
	//
	//ragged array
	int **table;
	table = (int**)malloc(5*sizeof(*table));
	for(int i = 0 ; i <5 ; i ++)
	{
		// *(table+i) = (int*)malloc(3*sizeof(int));
		table[i]=(int*)malloc(3*sizeof(int));
	}
	*(*(table+1)+1)=5;
	printf("%d\n", *(*(table+1)+1));





	
}