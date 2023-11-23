#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* Llink;
    struct node* Rlink;
};

struct node* createNode(int x){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->Llink=newNode->Rlink=NULL;
    return newNode;
}

struct node* createBST(struct node* root,int x){
    if(root==NULL){
        root=createNode(x);
    }
    else{
        if(x<root->data){
            root->Llink=createBST(root->Llink,x);
        }
        else{
            if(x>root->data){
            root->Rlink=createBST(root->Rlink,x);
            }
            else{
            printf("Duplicates arent allowed!");
            }
        }
    }
    return root;
}

struct node* searchBST(struct node* root,int x){
    if(root==NULL){
        printf("No tree exists");
        return NULL;
    }
    if(x<root->data){
       return searchBST(root->Llink,x);
    }
    if(x>root->data){
       return searchBST(root->Rlink,x);
    }
}

struct node* insertNode(struct node* root,int x){
    if(root==NULL){
        return createNode(x); //code is same as createBST except when root==NULL, we return createNOde(x). but we make root=createNode(x) in createBST function
    }
    if(x<root->data){
        root->Llink=insertNode(root->Llink,x);
    }
    if(x>root->data){
        root->Rlink=insertNode(root->Rlink,x);
    }
    return root;
}

struct node* findMin(struct node* node){
    while(node->Llink!=NULL){
        node=node->Llink;
    }
    return node;
}

struct node* findMax(struct node* node){
    while(node->Rlink!=NULL){
        node=node->Rlink;
    }
    return node;
}

struct node* deleteNode(struct node* root, int value){
    //tree is empty
    if(root==NULL){
        return root;
    }
    //traverse unti node is found that is to be deleted
    if(value<root->data){
        root->Llink=deleteNode(root->Llink,value);
    }
    if(value>root->data){
        root->Rlink=deleteNode(root->Rlink,value);
    }
    else{
        if(root->Llink==NULL){

        }
        if(root->Rlink==NULL){

        }
    }
}