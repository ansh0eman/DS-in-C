#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node* newNode(int data){
    struct Node * node = (struct Node *)malloc (sizeof(struct Node));
    node->data=data;
    node->next = NULL;
    return node;
}

void reverse(struct Node** head){
    struct Node* prev =NULL;
    struct Node* current =*head;
    struct Node* next = NULL;

    while(current!=NULL){
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }
    *head = prev;
}

struct Node* reverseRecursive(struct Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct Node* newhead =reverseRecursive(head->next);
    head->next->next =head;
    head->next =NULL;

    return newhead;
}

void printList(struct Node** head){
    struct Node* ptr = *head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr =ptr->next; 
    }
    printf("\n");
}

void peekHead(struct Node** head){
    if(*head){
        printf("Head: %d \n",(*head)->data);
    }
}

int main(){
    struct Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(40);
    printf("Old list:\n");
    printList(&head);
    // reverse(&head);
    // printf("New list after reversing iteratively:\n");
    // printList(&head);
    peekHead(&head);
    printf("Old list by reversing Recursively:\n");
    printList(&head);

}