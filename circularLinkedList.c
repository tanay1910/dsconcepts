#include<stdio.h>
#include<stdlib.h>

#define Max 10

struct Node{
	int data;
	struct Node* next;
};

struct Node* start = NULL;
struct Node* rear = NULL;

void createNode(int n){
	struct Node* temp = (struct Node* )malloc(sizeof(struct Node));
	temp->data=n;
	temp->next=NULL;
	if(start==NULL)
	{
		start = temp;
		rear = temp;
		rear->next=start;
	}
	else{
		temp->next=start;
		rear->next=temp;
		rear = temp;
	}
}

void displayCL()
{
	struct Node* temp = start;
	while(temp->next!=NULL)
	{
		printf("%d ",temp->data );
		temp = temp->next;
	}
	return;

}

void main()
{

	createNode(1);
	createNode(2);
	createNode(3);
	displayCL();

}