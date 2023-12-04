#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Structure for a binary tree node
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build a binary tree from a postfix expression
struct Node* buildExpressionTree(char postfix[]) {
    struct Node* stack[100]; // Assuming maximum 100 nodes
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {  //Alphabet or a Number (Operand)

            struct Node* node = createNode(postfix[i]);

            stack[++top] = node; //Push it onto the stack

        } else {  //Operator

            struct Node* node = createNode(postfix[i]);
            node->right = stack[top--];
            node->left = stack[top--];

            stack[++top] = node; //Push the operand node onto the stack
        }
    }
    printf("%d\n",top);
    return stack[top]; // Return the root of the tree
}

// Function to perform inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// Main function
int main() {
    char postfix[] = "ab+c*d/";

    // Build the binary tree from the postfix expression
    struct Node* root = buildExpressionTree(postfix);

    // Print the infix expression by performing inorder traversal of the constructed tree
    printf("Infix expression from the tree: ");
    inorder(root);

    return 0;
}
