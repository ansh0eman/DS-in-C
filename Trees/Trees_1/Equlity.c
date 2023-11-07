#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to check the equality of two binary trees
bool isSameTree(struct Node* p, struct Node* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }
    return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
/*int Equal( Nodeptr root1, Nodeptr root2){
    return ((!root1 && !root2) || (root1 && root2 &&(root1→data == root2→data) && 
    Equal( root1->lchild,root2->lchild) && Equal ( root1->rchild,root2->rchild));
}

*/

// Main function
int main() {
    // Create two sample binary trees
    struct Node* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(3);

    struct Node* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);

    // Check the equality of the trees and print the result
    if (isSameTree(root1, root2)) {
        printf("The trees are equal.\n");
    } else {
        printf("The trees are not equal.\n");
    }

    return 0;
}
