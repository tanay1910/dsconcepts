#include <stdio.h>
#include <stdbool.h>

// Define a structure for the stack
#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Check if the stack is empty
bool isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Push an item onto the stack
void push(struct Stack *s, char value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
    } else {
        s->items[++(s->top)] = value;
    }
}

// Pop an item from the stack
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return '\0';
    } else {
        return s->items[(s->top)--];
    }
}

// Function to check for balanced parentheses
bool areParenthesesBalanced(char *expr) {
    struct Stack s;
    initialize(&s);

    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&s, expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (isEmpty(&s)) {
                return false; // Unbalanced parentheses
            }
            char top = pop(&s);
            if ((expr[i] == ')' && top != '(') ||
                (expr[i] == '}' && top != '{') ||
                (expr[i] == ']' && top != '[')) {
                return false; // Mismatched parentheses
            }
        }
    }

    return isEmpty(&s); // If the stack is empty, parentheses are balanced
}

int main() {
    char expr[MAX_SIZE];
    printf("Enter an expression: ");
    // gets(expr);

    if (areParenthesesBalanced("a{(b+c)-e")) {
        printf("Parentheses are balanced.\n");
    } else {
        printf("Parentheses are not balanced.\n");
    }

    return 0;
}
