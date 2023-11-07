#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* lchild;
    struct Node* rchild;
};

// Typedef to simplify the node type
typedef struct Node* Nodeptr;

// Function to create a new node
Nodeptr getnode() {
    return (Nodeptr)malloc(sizeof(struct Node));
}

void insert(Nodeptr root, char direction[], int ele) {
    int i = 0;
    Nodeptr temp, cur, parent;
    temp = getnode();
    temp->data = ele;
    temp->lchild = temp->rchild = NULL;

    parent = NULL;
    cur = root;

    while (cur && direction[i]) {
        parent = cur;
        if (direction[i] == 'L' || direction[i] == 'l')
            cur = cur->lchild;
        else
            cur = cur->rchild;
        i++;
    }

    if (cur != NULL || direction[i] != '\0') {
        printf("Insertion Not possible\n");
        free(temp);
        return;
    }

    if (direction[i - 1] == 'L' || direction[i - 1] == 'l')
        parent->lchild = temp;
    else
        parent->rchild = temp;
}

// Function to perform in-order traversal of the binary tree
void inOrderTraversal(Nodeptr root) {
    if (root != NULL) {
        inOrderTraversal(root->lchild);
        printf("%d ", root->data);
        inOrderTraversal(root->rchild);
    }
}

// Main function
int main() {
    Nodeptr root = getnode();
    root->data = 1;
    root->lchild = root->rchild = NULL;

    // Insert nodes into the binary tree using direction strings
    insert(root, "L", 2); // Insert 2 as left child
    insert(root, "R", 3); // Insert 3 as right child
    insert(root, "LL", 4); // Insert 4 as left child of the left child

    // Print the binary tree using in-order traversal
    printf("Binary Tree (In-order traversal): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
