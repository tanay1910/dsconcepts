#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Stack data structure
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Push an element onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow.\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow.\n");
        return '\0'; // Return a sentinel value to indicate an error
    }
    return stack->items[stack->top--];
}

// Get the precedence of an operator
int getPrecedence(char operator) {
    if (operator == '^')
        return 3;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return 0;
}

// Check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Convert infix expression to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    struct Stack operatorStack;
    initialize(&operatorStack);
    
    int infixLen = strlen(infix);
    int prefixIndex = 0;
    
    // Reverse the infix expression
    for (int i = infixLen - 1; i >= 0; i--) {
        if (infix[i] == ' ')
            continue;
        
        // If it's an operand, copy it to the prefix expression
        if (!isOperator(infix[i])) {
            prefix[prefixIndex++] = infix[i];
        }
        // If it's an operator
        else {
            // Pop operators from the stack until an operator with lower precedence is encountered
            while (!isEmpty(&operatorStack) && getPrecedence(operatorStack.items[operatorStack.top]) >= getPrecedence(infix[i])) {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            // Push the current operator onto the stack
            push(&operatorStack, infix[i]);
        }
    }
    
    // Pop any remaining operators from the stack
    while (!isEmpty(&operatorStack)) {
        prefix[prefixIndex++] = pop(&operatorStack);
    }
    
    // Null-terminate the prefix expression
    prefix[prefixIndex] = '\0';
    
    // Reverse the prefix expression to get the final result
    strrev(prefix);
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];
    
    printf("Enter an infix expression: ");
    gets(infix);
    
    infixToPrefix(infix, prefix);
    
    printf("Prefix expression: %s\n", prefix);
    
    return 0;
}
