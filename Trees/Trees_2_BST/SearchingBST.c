#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to search a key in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    struct Node* root = NULL;
    int keys[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        root = insert(root, keys[i]);
    }

    int keyToFind = 40;
    struct Node* foundNode = search(root, keyToFind);

    if (foundNode != NULL) {
        printf("Key %d found in the BST\n", keyToFind);
    } else {
        printf("Key %d not found in the BST\n", keyToFind);
    }
    printf("%d ",foundNode->data);

    return 0;
}
