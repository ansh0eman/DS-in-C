
/*

Step 1: Initialize an empty stack to hold operators.

Step 2: Initialize an empty list to hold the output (postfix) expression.

Step 3: Scan the infix expression from left to right, one character at a time.

** If the current character is an operand (a letter or digit), add it to the output list.
** If the current character is an open parenthesis '(', push it onto the stack.
** If the current character is a close parenthesis ')', pop operators from the stack and append them to the output list until an open parenthesis '(' is encountered. Pop and discard the open parenthesis.
** If the current character is an operator (+, -, *, /, etc.), then:
While the stack is not empty and the precedence of the operator on top of the stack is greater than or equal to the precedence of the current operator (taking into account operator associativity), pop the operator from the stack and append it to the output list.
Push the current operator onto the stack.
Step 4: After scanning the entire infix expression, pop any remaining operators from the stack and append them to the output list.

Step 5: The output list now contains the postfix expression.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the stack
struct Stack {
    char* items;
    int top;
    int capacity;
};

// Function to create a new stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (char*)malloc(sizeof(char) * capacity);
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Error: Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Function to get the top item of the stack without popping
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        return '\0';
    }
    return stack->items[stack->top];
}

// Function to get the precedence of an operator
int precedence(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/')
        return 2;
    return 0; // Lower precedence for other characters
}

// Function to convert infix to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    struct Stack* stack = createStack(strlen(infix));

    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
            postfix[j++] = token;
        } else if (token == '(') {
            push(stack, token);
        } else if (token == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[j++] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) == '(') {
                pop(stack); // Pop '('
            } else {
                printf("Error: Mismatched parentheses\n");
                return;
            }
        } else { // Operator
            while (!isEmpty(stack) && precedence(token) <= precedence(peek(stack))) {
                postfix[j++] = pop(stack);
            }
            push(stack, token);
        }
    }

    while (!isEmpty(stack)) {
        if (peek(stack) == '(') {
            printf("Error: Mismatched parentheses\n");
            return;
        }
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
    free(stack->items);
    free(stack);
}

int main() {
    char infix[100], postfix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    if (postfix[0] != '\0') {
        printf("Postfix expression: %s\n", postfix);
    }

    return 0;
}
