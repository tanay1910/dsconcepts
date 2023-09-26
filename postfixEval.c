#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<string.h>

#define MAX_STACK_SIZE 100

// Stack implementation
struct Stack {
    int top;
    int items[MAX_STACK_SIZE];
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d\n", value);
        exit(1);
    }
    s->items[++s->top] = value;
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop\n");
        exit(1);
    }
    return s->items[s->top--];
}

int evaluatePostfix(char *expression) {
    struct Stack stack;
    initialize(&stack);

    int length = strlen(expression);

    for (int i = length - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            // If the character is a digit, convert it to an integer and push onto the stack
            push(&stack, expression[i] - '0');
        } else {
            // If the character is an operator, pop the top two values from the stack
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            // Perform the operation and push the result back onto the stack
            switch (expression[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator: %c\n", expression[i]);
                    exit(1);
            }
        }
    }

    // The final result is on top of the stack
    return pop(&stack);
}

int main() {
    char expression[] = "-+*523+23";
    int result = evaluatePostfix(expression);
    printf("Result of the expression: %d\n", result);
    return 0;
}
