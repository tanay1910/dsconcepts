#include<stdio.h>
#include<stdlib.h>

#define Max 10

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
    printf("Stack Elements: \n");
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->arr[i]);
    }
}

int main() {
    struct Stack* s1;
    s1 = createStack();
    printf("%d\n", s1->top);

    Push(s1, 5);
    display(s1);
    Push(s1, 6);
    display(s1);
    Push(s1, 7);
    display(s1);

    // Free the allocated memory before the program exits
    free(s1);

    return 0;
}
