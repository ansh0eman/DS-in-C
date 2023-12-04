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

Nodeptr CreateBinaryTree(int item){
    int x;
    if (item!=-1) { //until input is not equal to -1
        Nodeptr temp = getnode();
        temp->data = item;
        printf("Enter the lchild of %d :",item);
        scanf("%d",&x);
        temp->lchild = CreateBinaryTree(x);
        printf("Enter the rchild of %d :",item);
        scanf("%d",&x);
        temp->rchild = CreateBinaryTree(x);
        return temp;
    }
    return NULL;
}


// Main function
int main() {
    Nodeptr root = getnode();
    int item;
    printf("Creating the tree : \n");
    printf("Enter the root :");
    scanf("%d",&item);
    root=CreateBinaryTree(item);
    // Print the binary tree using in-order traversal
    printf("Binary Tree (In-order traversal): ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
