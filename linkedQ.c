#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct cirQ{
	struct Node* front;
	struct Node* rear;
};

struct cirQ* createCirQ()
{
	struct cirQ* cq;
	cq = (struct cirQ*)malloc(sizeof(struct cirQ));
	cq->front=cq->rear=NULL;
	return(cq);
}


void enQ(struct cirQ* cq, int val)
{
	struct Node* newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data=val;
	newNode->next=NULL;

	if(cq->rear==NULL)
	{
		cq->front=cq->rear=newNode;
	}
	else{
		cq->rear->next=newNode;
		cq->rear=newNode;
	}

}

void deQ(struct cirQ* cq)
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp=cq->front;
	if(cq->rear==NULL)
	{
		printf("Q empty.\n");
		return;
	}
	else if(cq->front==cq->rear)
	{
		printf("%d deqeued.\n",cq->front->data);
		cq->front=cq->rear=NULL;
	}
	else{
		printf("%d deqeued.\n",cq->front->data);
		cq->front=cq->front->next;

	}

}

void main()
{
	struct cirQ* cq;
	cq=createCirQ();
	enQ(cq,5);
	printf("front: %d\n",cq->front->data );
	enQ(cq,6);
	enQ(cq,7);
	printf("rear: %d\n",cq->rear->data);
	deQ(cq);
	printf("front: %d\n",cq->front->data );
	deQ(cq);
	deQ(cq);
	deQ(cq);

}