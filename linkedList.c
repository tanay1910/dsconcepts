#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* start = NULL;

struct Node* creatNode(int val)
{	
	struct Node* node;
	node = (struct Node* )malloc(sizeof(struct Node));
	node->data=val;
	node->next=NULL;
	if(start==NULL)
	{
		start = node;
	}
	else{
		struct Node* temp;
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp=start;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next=node;
	}

}

void insertAfterElement(struct Node* start, int ele, int val)
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp=start;
	while(temp->data!=ele)
	{
		temp=temp->next;
	}
	struct Node* newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=val;
	newNode->next=temp->next;
	temp->next=newNode;

}

int isEmpty(struct Node* node)
{
	return(start==NULL);
}

void display(struct Node* node)
{
	if(isEmpty(start))
	{
		printf("LL empty\n");
		return;
	}

	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp=start;
	while(temp!=NULL)
	{
		printf("%d ",temp->data );
		temp=temp->next;
	}
}

void main()
{
	creatNode(5);
	creatNode(6);
	creatNode(7);
	display(start);
	insertAfterElement(start,6,10);
	display(start);
}