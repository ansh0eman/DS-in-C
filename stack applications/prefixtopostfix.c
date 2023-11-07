/*We define a stack structure for characters as before.
We read a prefix expression and reverse it to make it easier to process from left to right.
We process the reversed prefix expression from left to right, pushing operands onto the stack and performing operations when operators are encountered.
We concatenate the result of each operation to the postfix expression.
Finally, we print the resulting postfix expression.
Compile and run the program, and it will prompt you to enter a prefix expression, and it will display the corresponding postfix expression.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define a stack-like structure using a character array and an index
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

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Error: Stack overflow\n");
        exit(1); // Exit with an error code
    }
    stack->items[++stack->top] = item;
}

// Function to pop an element from the stack
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

// Function to convert prefix to postfix expression
void prefixToPostfix(char* prefix, char* postfix) {
    struct Stack operatorStack;
    initStack(&operatorStack);
    
    int len = strlen(prefix);
    
    // Process the prefix expression from right to left
    for (int i = len - 1; i >= 0; i--) {
        char token = prefix[i];
        
        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z')) {
            push(&operatorStack, token);
        } else if (token == '+' || token == '-' || token == '*' || token == '/') {
            char operand1 = pop(&operatorStack);
            char operand2 = pop(&operatorStack);
            char result[3] = {operand1, operand2, token};
            strcat(result, postfix); // Append the result to the postfix expression
            strcpy(postfix, result);
        }
    }
}

int main() {
    char prefix[100], postfix[100];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    
    prefixToPostfix(prefix, postfix);
    
    if (postfix[0] != '\0') {
        printf("Postfix expression: %s\n", postfix);
    }
    
    return 0;
}
