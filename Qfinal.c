#include<stdio.h>
#include<stdlib.h>

#define Max 10

struct Queue{
	int arr[Max];
	int front,rear;
};

struct Queue* createQ()
{
	struct Queue* q;
	q=(struct Queue*)malloc(sizeof(struct Queue));
	q->front=-1;
	q->rear=-1;
}

int isFull(struct Queue* q)
{
	return(q->front==0 && q->rear==Max-1);
}

int isEmpty(struct Queue* q)
{
	return(q->front==-1&&q->rear==-1);
}

void enQ(struct Queue* q, int num)
{
	if(isFull(q))
	{
		printf("Q full.\n");
		return;
	}
	if(isEmpty(q))
	{
		q->front=0;
		q->rear=0;
		q->arr[q->front]=num;
	}
	else{
		q->arr[++q->rear]=num;
	}
}

void deQ(struct Queue* q)
{
	if(isEmpty(q))
	{
		printf("Q empty!\n");
		return;
	}
	if(q->front==q->rear)
	{
		printf("%d deQed.\n",q->arr[q->front]);
		q->front=q->rear=-1;
	}
	else{
		printf("%d deQed!\n",q->arr[q->front]);
		q->front++;
	}
}

void display(struct Queue* q)
{
	if(isEmpty(q))
	{
		printf("Q Empty!\n");
		return;
	}
	// for(int i = 0 ; i<Max; i++)
	// {
	// 	printf("%d ",q->arr[i]);
	// }
	// printf("\n");

	for(int i = q->front; i<q->rear+1; i++)
	{
		printf("%d ",q->arr[i]);
	}
	printf("\n");
}


void main()
{
	struct Queue* q1;
	q1=createQ();
	enQ(q1,1);
	// printf("%d\n",q1->front);
	display(q1);

	enQ(q1,2);
	enQ(q1,3);
	enQ(q1,4);
	display(q1);
	deQ(q1);
	printf("%d\n",q1->front);
	display(q1);


	// printf("%d",q1->arr[0]);
}
