#include<stdio.h>
#include<stdlib.h>

#define Max 15

struct DEQ{
	int data[Max];
	int front, rear;
};

struct DEQ* createDEQ()
{
	struct DEQ* dq;
	dq=(struct DEQ*)malloc(sizeof(struct(DEQ)));
	dq->front=-1;
	dq->rear=-1;
}

int isFull(struct DEQ* dq)
{
	return(dq->front==0 && dq->rear==Max-1 || dq->rear==(dq->front-1)%Max);
}

int isEmpty(struct DEQ* dq)
{
	return(dq->front==-1);
}

void pushback(struct DEQ* dq, int val)
{
	if(isFull())
	{
		printf("DQ is full!\n");
		return;
	}
	else if (dq->front==-1)
	{
		dq->front=dq->rear=0;
		dq->data[dq->front]=val;
		printf("%d pushed from back!\n");
	}
	else if(dq->rear==Max-1 && dq->front!=0)
	{
		dq->rear=0;
		dq->data[dq->rear]=val;
		printf("%d pushed from back!\n");
	}
	else{
		dq->rear ++;
		dq->data[dq->rear]=val;
	}
}

void popback(struct DEQ* dq)
{
	if(isEmpty(dq))
	{
		printf("DQ empty!\n");
		return
	}
	else if (dq->front == dq->rear)
	{
		int val1 = dq->data[dq->rear];
		print("%d popped from back",dq->data[dq->rear]);
		dq->rear=dq->front=-1;
	}
	else if (dq->rear==Max-1 && dq->front!=0)
	{
		printf("%d popped from back.\n",dq->rear[dq->data]);
		dq->rear=0;
	}
	else{
		printf("%d popped from back.\n",dq->rear[dq->data]);
		dq->rear
	}
}