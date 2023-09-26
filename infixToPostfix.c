#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char operatorStack[MAX_SIZE];
int operatorTop = -1;

char postfixExpression[MAX_SIZE];
int postfixTop = -1;

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0;  // If the character is not an operator
}

void pushOperator(char operator) {
    operatorStack[++operatorTop] = operator;
}

char popOperator() {
    return operatorStack[operatorTop--];
}

void pushPostfix(char character) {
    postfixExpression[++postfixTop] = character;
}

void infixToPostfix(char infixExpression[]) {
    int length = strlen(infixExpression);

    for (int i = 0; i < length; i++) {
        char currentChar = infixExpression[i];

        if (currentChar == ' ')
            continue;  // Skip spaces

        if (isOperator(currentChar)) {
            while (operatorTop >= 0 && getPrecedence(currentChar) <= getPrecedence(operatorStack[operatorTop])) {
                char poppedOperator = popOperator();
                pushPostfix(poppedOperator);
            }
            pushOperator(currentChar);
        } else if (currentChar == '(' || currentChar == '[') {
            pushOperator(currentChar);
        } else if (currentChar == ')' || currentChar == ']') {
            while (operatorTop >= 0 && operatorStack[operatorTop] != '(' && operatorStack[operatorTop] != '[') {
                char poppedOperator = popOperator();
                pushPostfix(poppedOperator);
            }
            popOperator();  // Pop the corresponding opening parenthesis
        } else {
            pushPostfix(currentChar); // Operand
        }
    }

    while (operatorTop >= 0) {
        char poppedOperator = popOperator();
        pushPostfix(poppedOperator);
    }

    // Add null terminator to the postfix expression
    postfixExpression[postfixTop + 1] = '\0';
}

int main() {
    char infixExpression[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s",infixExpression);

    infixToPostfix(infixExpression);

    printf("Postfix expression: %s\n", postfixExpression);

    return 0;
}
