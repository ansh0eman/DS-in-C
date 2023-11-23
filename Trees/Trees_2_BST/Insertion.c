//Same as Creation (using recursively)

//Using iteratively (using Loops):

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value) {
    struct Node *newNode = createNode(value);
    struct Node *parent = NULL;
    struct Node *cur = root;

    while (cur != NULL) {
        parent = cur;
        if (value < cur->data)
            cur = cur->left;
        else if (value > cur->data)
            cur = cur->right;
        else {
            free(newNode); // Avoid duplicate elements
            return root;
        }
    }

    if (parent == NULL)
        return newNode; // Tree is empty

    if (value < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

void inOrderTraversal(struct Node *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    struct Node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("In-order traversal of the BST after insertion: ");
    inOrderTraversal(root);

    return 0;
}
