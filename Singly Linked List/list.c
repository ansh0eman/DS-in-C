#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head=NULL;

struct node* createNode(int x){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}

struct node* insertAtEnd(struct node** head,int x){
    struct node* newNode = createNode(x);
    if(*head==NULL){
        *head=newNode;
    }
    else{
        struct node* temp = *head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}

// GO THROUGH THIS THOUROUGHLY!!!

void deleteNode(struct node **head, int x){
    struct node* current;
    struct node* prev=NULL;
    while(current!=NULL && current->data!=x){
        prev=current;
        current=current->next;
    }

    if(current==NULL){
        printf("The node doesn't exist");
    }
    if(prev==NULL){
        *head=current->next;
    }
    else{
        prev->next=current->next;
    }

    free(current);
}