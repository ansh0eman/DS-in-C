#include <stdio.h>
#include <stdlib.h>
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

// Function to evaluate the expression tree
int eval(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->data - '0'; // Convert character to integer
    }
    
    // int leftValue = eval(root->left);
    // int rightValue = eval(root->right);

    switch (root->data) {
        case '+':
            return eval(root->left) + eval(root->right);
        case '-':
            return eval(root->left) - eval(root->right);
        case '*':
            return eval(root->left) * eval(root->right);
        case '/':
            return eval(root->left) / eval(root->right);
        default:
            return 0; // Invalid operator
    }
}

// Main function
int main() {
    // Create the expression tree: 3 + 5 * 2
    struct Node* root = createNode('+');
    root->left = createNode('3');
    root->right = createNode('*');
    root->right->left = createNode('5');
    root->right->right = createNode('2');

    // Evaluate the expression tree and print the result
    int result = evaluateExpressionTree(root);
    printf("Result of the expression: %d\n", result);

    return 0;
}
