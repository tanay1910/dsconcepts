#include<stdio.h>
#include<stdlib.h>

#define Max  50

struct Node{
	int data;
	struct Node* next;
}*temp;

struct LinkedStack{
	struct Node* top;
};





void push(struct Node* top,int val)
{
	struct LinkedStack* lstack;
	lstack=(struct LinkedStack*)malloc(sizeof(LinkedStack));
	l

	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=val;;
	temp->next=NULL;
	if(top==NULL)
	{
		top=temp;

	}
	else{
		temp->next=top;
		top=temp;
	}
}

void display(struct Node* top)
{
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp=top;
	while(temp!=NULL)
	{
		printf("%d ",temp->data );
		temp=temp->next;
	}
}

void main()
{
	struct Node* top;
	top=(struct Node*)malloc(sizeof(struct Node));

	push(top,5);
	push(top,6);
	push(top,7);
	printf("%d ",top->data);
}