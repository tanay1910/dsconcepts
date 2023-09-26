#include <stdio.h>
#include<stdlib.h>

int binarySearch(int item, int arr[], int low, int high)
{
	int mid;
	if(low>high)
		return -1;
	mid=(high+low)/2;
	if (item == arr[mid])
		return mid;
	else if (item<arr[mid])
	{
		high=mid-1;
		return(binarySearch(item,arr,low,high));
	}
	else
	{
		low=mid+1;
		return(binarySearch(item,arr,low,high));
	}
}

void main()
{
	int item;
	item=4;
	int arr[]={2,4,5,6};
	printf("%d\n",binarySearch(item,arr,0,4) );
}