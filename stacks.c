#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

struct Stack {
	int top;
	int* array;
	unsigned capacity;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*) malloc (sizeof(struct Stack));
	stack->capacity=capacity;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	stack->top=-1;
	return stack;
}

int isFull(struct Stack* stack)
{
	return (stack->top == stack->capacity-1);
}

int isEmpty(struct Stack* stack)
{
	return(stack->top==-1);
}

void push(struct Stack* stack, int num)
{
	if (isFull(stack))
	{
		printf("stack overflow!");
		return;
	}
	else{
		stack->array[(stack->top)++]=num;
		printf("%d pushed to stack.",num);

	}
}

void pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return;
    printf("%d popped.\n",stack->array[stack->top]);
    stack->top--;
}

void main()
{
	unsigned capacity;
	printf("Enter the size of stack: ");
	scanf("%u",&capacity);

	struct Stack* s1 = createStack(capacity);	

	printf("Top:%d\n",s1->top);

	push(s1,5);
	printf("\nTop:%d\n",s1->top);	

	push(s1,6);
	printf("\nTop:%d\n",s1->top);

	
	pop(s1);
	printf("\nTop:%d\n",s1->top);

}