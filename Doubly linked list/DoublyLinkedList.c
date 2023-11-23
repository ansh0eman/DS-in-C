#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* Llink;
    struct node* Rlink;
};

struct node* head;

struct node* createNode(int x){
    struct node* newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data=x;
    newNode->Llink=NULL;
    newNode->Rlink=NULL;
    return newNode;
}

void insertAtHead(int x){
    struct node* temp= createNode(x);
    if(head==NULL){
        head=temp;
    }

    head->Llink=temp;
    temp->Rlink=head;
    head=temp;
}