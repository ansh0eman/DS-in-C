#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Structure for a stack
struct Stack {
    int top;
    struct Node* array[MAX_STACK_SIZE];
};

// Function to create a new stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, struct Node* item) {
    if (stack->top >= MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
struct Node* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

// Function to create a new binary tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to perform iterative preorder traversal
void iterativePreorder(struct Node* root) {
    if (root == NULL) return;

    struct Stack* stack = createStack();
    push(stack, root);

    while (!isEmpty(stack)) {
        struct Node* current = pop(stack);
        printf("%d ", current->data);

        // Push the right child first (since stack is LIFO)
        if (current->right)
            push(stack, current->right);
        if (current->left)
            push(stack, current->left);
    }
}

// Main function
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Iterative Preorder Traversal: ");
    iterativePreorder(root);
    printf("\n");

    return 0;
}
