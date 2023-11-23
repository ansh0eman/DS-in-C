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

void insertFront(struct Node** head,int data){
    struct Node * node = newNode(data);
    node->next = *head;
    *head = node;
    //return head; 
    //NO NEED OF RETURNING AS WE ARE SENDING **HEAD
}

void insertRear(struct Node** head, int data){
    struct Node * node = newNode(data);
    if(*head ==NULL){
        *head = node;
    }
    struct Node* ptr =*head;
    while(ptr->next !=NULL){
        ptr=ptr->next;
    }
    ptr->next =node;
}

void insertAfter(struct Node** head, int prevElement, int data){
    struct Node* ptr = *head;
    while(ptr!=NULL && ptr->data != prevElement){
        ptr =ptr->next;
    }
    struct Node* node = newNode(data);
    node->next = ptr->next;
    ptr->next = node;
}

void deleteNode(struct Node** head, int key){
    struct Node* ptr = *head;
    struct Node* prev =NULL;
    if(ptr!=NULL && ptr->data == key){ //key present at head
        *head = ptr->next;
        free(ptr);
        return;
    }
    while(ptr!=NULL && ptr->data == key){
        prev = ptr;
        ptr= ptr->next;
    }

    if(ptr ==NULL){ //key not present in LL
        printf("key not found");
    }
    printf("Element %d deleted succesfully\n",ptr->data);

    prev->next = ptr->next;
    free(ptr);
}
void peekHead(struct Node** head){
    if(*head){
        printf("Head: %d ",(*head)->data);
    }
}

void printList(struct Node** head){
    struct Node* ptr = *head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr =ptr->next; 
    }
    printf("\n");
}

void freeLL(struct Node** head){
    struct Node* ptr = *head;
    struct Node* temp = NULL;
    while(ptr!=NULL){
        temp =ptr;
        ptr=ptr->next;
        free(temp);
    }
    *head = NULL;
}

int main(){
    struct Node * head =NULL;
    int inp;
    while(inp !=-1){
    printf("1.insertFront , 2.insertRear, 3.insertAfter, 4.deleteNode, 5.print, 6.FreeLL, 7.peekHead-1.Exit\n");
    scanf("%d",&inp);
    switch (inp)
    {
    case 1:
        printf("Enter element insertFront :\n");
        int data;
        scanf("%d",&data);
        insertFront(&head,data);
        break;
    case 2:
        printf("Enter element insertRear:\n");
        int dataRear;
        scanf("%d",&dataRear);
        insertRear(&head, dataRear);
        break;
    case 3:
        printf("Enter element insertAfter and key respectively: \n");
        int key, dataAfter;
        scanf("%d %d",&dataAfter,&key);
        insertAfter(&head, key, dataAfter);
        break;
    case 4:
        printf("Enter element to delete:\n");
        int delkey;
        scanf("%d",&delkey);
        deleteNode(&head, delkey);
        break;
    case 5:
        printf("Linked List: \n");
        printList(&head);
        break;
    case 6:
        freeLL(&head);
        break;
    case 7:
        peekHead(&head);
        break;
    case -1:
        return 0;
    }
}
}