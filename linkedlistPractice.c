#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* start = NULL;

void create(int num)
{
	struct Node* temp, *ptr;
	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data=num;
	temp->next=NULL;
	if(start==NULL)
	{
		start = temp;
	}
	else{
		ptr = start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
}

void display(struct Node* node)
{
	if(start==NULL)
	{
		printf("LL is empty! \n");
		return;
	}
	else{
		struct Node* temp;
		temp = (struct Node*)malloc(sizeof(struct Node));
		temp = start;
		while(temp->next!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}

void insertStart(struct Node* node, int num)
{
	struct Node* temp;
	temp = (struct Node*) malloc(sizeof(struct Node));
	temp->data=num;
	temp->next=start;
	start=temp; 
}

void insertAfterElement(struct Node* n1, int ele, int num)
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data=num;

	struct Node* ptr;
	ptr = (struct Node*)malloc(sizeof(struct Node));

	ptr=start;
	while(ptr->data!=ele)
	{
		ptr=ptr->next;
	}
	temp->next=ptr->next;
	ptr->next=temp;
}

void deleteFirst(struct Node* n1)
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp=start;
	start=start->next;
	printf("Removing start: %d\n",temp->data);
	free(temp);
}
void main()
{
	struct Node* n1;
	create(5);
	create(7);
	create(8);
	create(9);
	printf("Current data: %d\n",start->data );
	insertStart(n1,4);
	printf("Current data: %d\n",start->data );
	insertAfterElement(n1,5,6);
	printf("Current data: %d\n",start->next->next->data );
	deleteFirst(n1);
	display(n1);

	

}