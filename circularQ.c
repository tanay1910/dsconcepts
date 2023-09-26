#include<stdio.h>
#include<stdlib.h>

#define Max 4

struct CircQ {
	int data[Max];
	int front, rear;
};

int isFull(struct CircQ* cq){
	return(cq->front==0 && cq->rear==Max-1 || cq->rear==(cq->front-1)%Max);
}

void enQ(struct CircQ* cq)
{
	int data;
	printf("Enter data: ");
	scanf("%d",&data);

	if(isFull(cq))
	{
		printf("Q is full.\n");
		return;
	}
	else if(cq->front==-1)
	{
		cq->front=cq->rear=0;
		cq->data[cq->rear]=data;
	}
	else if(cq->rear==Max-1 && cq->front!=0)
	{
		cq->rear=0;
		cq->data[cq->rear]=data;
	}
	else{
		cq->rear++;
		cq->data[cq->rear]=data;
	}
}

int isEmpty(struct CircQ* cq)
{
	return(cq->front==-1);
}

void dequeu(struct CircQ* cq)
{
	if(isEmpty(cq))
	{
		printf("Q empty!\n");
		return;
	}
	else if(cq->front==cq->rear)
	{
		int val = cq->data[cq->front];
		cq->front=cq->rear=-1;
		printf("%d dQed\n",val);
	}
	else if(cq->front==Max-1)
	{
		int val=cq->data[cq->front];
		printf("%d dQed!\n",val);
		cq->front=0;
	}
	else{
		int val=cq->data[cq->front];
		printf("%d dQed!\n",val);
		cq->front=cq->front+1;
		
	}
}




void main()
{
	struct CircQ* cq;
	cq = (struct CircQ*)malloc(sizeof(struct CircQ));
	cq->front=-1;
	cq->rear=-1;
	printf("%d \n",cq->front);
	printf("%d \n",cq->rear);
	enQ(cq);
	printf("%d \n",cq->front);
	printf("%d \n",cq->rear);
	enQ(cq);
	printf("%d \n",cq->front);
	printf("%d \n",cq->rear);
	enQ(cq);
	printf("%d \n",cq->front);
	printf("%d \n",cq->rear);
	enQ(cq);
	printf("%d \n",cq->front);
	printf("%d \n",cq->rear);;

	dequeu(cq);
	printf("%d \n",cq->front);
	printf("%d \n",cq->rear);;

	enQ(cq);
	printf("%d \n",cq->front);
	printf("%d \n",cq->rear);;

	// printf("Element: %d\n",cq->data[0]);
	// dequeu(cq);
	
	




}