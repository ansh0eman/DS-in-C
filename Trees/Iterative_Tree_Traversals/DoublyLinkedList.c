#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

struct node{
    int data;
    struct node* Llink;
    struct node* Rlink;
};

struct node* createNode(int info){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=info;
    newNode->Llink = newNode->Rlink = NULL;
    return newNode;
}

void insertAtEnd(struct node ** head, int value){
    struct node* Node= createNode(value);
        if(*head == NULL){
            *head=Node;
        }
        else{
            struct node* temp = head;
                while(temp->Llink==NULL){
                    temp=temp->Llink;
                }
                temp->Rlink=Node;
                Node->Llink=temp;
        }
}

int main(){
    struct node* head = NULL;
    int x,data;
    do {
        printf("Choose an option:\n");
        printf("1. Insert at the end\n");
        printf("2. Display the list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &x);

        switch (x) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 2:
                printf("Doubly Linked List: ");
               // traverse(head);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (x != 3);

}