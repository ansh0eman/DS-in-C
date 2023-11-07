/*Step 1: Reverse the Infix Expression.

Reverse the given infix expression, i.e., reverse the order of characters.
Step 2: Convert the Reversed Infix Expression to Postfix.

Use the Shunting Yard algorithm (as described earlier for postfix conversion) to convert the reversed infix expression to postfix.
Step 3: Reverse the Postfix Expression.

Reverse the resulting postfix expression to obtain the prefix expression.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a stack structure
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Error: Stack overflow\n");
        exit(1); // Exit with an error code
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow\n");
        exit(1); // Exit with an error code
    }
    return stack->items[stack->top--];
}

// Function to get the top item of the stack without popping
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        exit(1); // Exit with an error code
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

// Function to reverse a string
void reverseString(char* str) {
    int len = strlen(str);
    int i, j;
    for (i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert infix to prefix expression
void infixToPrefix(char infix[], char prefix[]) {
    struct Stack operatorStack;
    initStack(&operatorStack);

    int i, j = 0;
    char reversedInfix[100];
    strcpy(reversedInfix, infix);
    reverseString(reversedInfix);

    for (i = 0; reversedInfix[i] != '\0'; i++) {
        char token = reversedInfix[i];

        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
            prefix[j++] = token;
        } else if (token == ')') {
            push(&operatorStack, token);
        } else if (token == '(') {
            while (!isEmpty(&operatorStack) && peek(&operatorStack) != ')') {
                prefix[j++] = pop(&operatorStack);
            }
            if (!isEmpty(&operatorStack) && peek(&operatorStack) == ')') {
                pop(&operatorStack); // Pop ')'
            } else {
                printf("Error: Mismatched parentheses\n");
                exit(1); // Exit with an error code
            }
        } else { // Operator
            while (!isEmpty(&operatorStack) && peek(&operatorStack) != ')' && precedence(token) <= precedence(peek(&operatorStack))) {
                prefix[j++] = pop(&operatorStack);
            }
            push(&operatorStack, token);
        }
    }

    while (!isEmpty(&operatorStack)) {
        prefix[j++] = pop(&operatorStack);
    }

    prefix[j] = '\0';
    reverseString(prefix);
}

int main() {
    char infix[100], prefix[100];
    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    if (prefix[0] != '\0') {
        printf("Prefix expression: %s\n", prefix);
    }

    return 0;
}
