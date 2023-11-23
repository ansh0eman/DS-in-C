#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * createNode(int item){
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data =item;
    newNode->left = newNode->right =NULL;
    return newNode;
}

struct Node * insert(struct Node* root, int value){
    //no BST 
    if(root == NULL){
        return createNode(value);
    }
    
    if(value < root->data){
        root->left = insert(root->left, value);
    }
    else if(value > root->data){
        root->right = insert(root->right, value);
    }
    else{
        printf("Duplicates are not allowed.\n");
    }
    
    return root;
}

void inOrderTraversal(struct Node * root){
    if (root !=NULL){
     inOrderTraversal(root->left);
     printf("%d ", root->data);
     inOrderTraversal(root->right);
    }
}

int main(){
    struct Node * root =  NULL;
    int item;

    printf("Enter data into BST (Enter negative value to end.): ");
    while(1){
        scanf("%d ",&item);
        if(item >=0){
           root = insert(root, item);
        }
        else
            break;
    }
    printf("InOrder traversal of BST: ");
    inOrderTraversal(root);
}
