#include<stdio.h>
#include<stdlib.h>

struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
}; 

struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*) malloc (sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0 ;
	queue->rear = capacity - 1;
}

int isFull(struct Queue* q1)
{
	if(q1->size==q1->capacity)
		return 1;
	else
		return 0;
}

int isEmpty(struct Queue* q1)
{
	return(q1->size==0);
}

void enQ(struct Queue* q1, int num)
{
	if(isFull(q1))
	{
		printf("Full!\n");
		return;
	}
	q1->rear = (q1->rear+1)%q1->capacity;
	(q1->size)++;
}

void deQ(struct Queue* q1)
{
	if(isEmpty(q1))
	{
		printf("Empty!\n");
		return;
	}
	int num1 = q1->array[q1->front];
	q1->front++;
	q1->size--;
	printf("%d deQed.",num1);
}

void display(struct Queue* q)
{
	for(int i = q->front ; i < q->rear; i++)
	{
		printf("%d ",q->array[i]);
	}
}


void main()
{
	struct Queue* q1;
	q1 = createQueue(5);
	enQ(q1,1);
	enQ(q1,2);
	printf("%d\n",q1->size);
	printf("%d\n",q1->capacity);
	enQ(q1,3);
	enQ(q1,4);
	printf("%d",q1->rear);
	deQ(q1);
	printf("%d",q1->front);
	
}