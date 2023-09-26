#include<stdio.h>
#include<stdlib.h>

#include<stdio.h>
#include<stdlib.h>

#define Max 50

struct Stack {
    int arr[Max];
    int top;
};

struct Stack* createStack() {
    struct Stack* s;
    s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = -1;
    return s;
}

int isFull(struct Stack* s) {
    return (s->top == Max - 1);
}

int isEmpty(struct Stack* s) {
    return (s->top == -1);
}

void Push(struct Stack* s, int val) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->arr[++s->top] = val;
    printf("%d pushed.\n", val);
    printf("New top: %d\n", s->top);
}

void Pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack empty!\n");
        return;
    }
    printf("%d popped.\n", s->arr[s->top]);
    s->top--;
}

void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Empty!\n");
        return;
    }
    printf("Converted top binary Elements: \n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d", s->arr[i]);
    }
}

int main() {
    struct Stack* s1;
    s1 = createStack();
    printf("%d\n", s1->top);

    int decimal;
    scanf("%d",&decimal);

    while(decimal!=0)
    {
    	int rem;
    	rem=decimal%2;
    	Push(s1,rem);
    	decimal/=2;
    }

    display(s1);


}
