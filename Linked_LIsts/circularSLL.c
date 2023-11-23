#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Failed\n");
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct Node **head, int data) {
    struct Node *node = newNode(data);
    if (*head == NULL) {
        // If the list is empty, make the new node the only node in the list
        *head = node;
        node->next = *head;
    } else {
        // Otherwise, traverse to the last node and update pointers
        struct Node *temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = node;
        node->next = *head;
    }
}

void insertFront(struct Node** head, int data){
    struct Node* node = newNode(data);
    node->next = *head;
    *head = node;
    //traverse to last node and change link
    struct Node* current = *head;
    while(current->next != *head){
        current = current->next;
    }
    current->next = *head;
}

int Length(struct Node* head) {
    if (head == NULL) {
        return 0; // List is empty
    }

    int length = 1; // Initialize to 1 for the head node
    struct Node* temp = head;
    while(temp->next!=head){
        length++;
        temp = temp->next;
    }

    return length;
}

// Function to print the elements of the circular linked list
void printList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

// Function to free the memory allocated for the circular linked list
void freeList(struct Node **head) {
    if (*head == NULL) {
        return;
    }

    struct Node *temp = *head;
    struct Node *current = *head;
    do {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != *head);

    *head = NULL;
}

int main() {
    struct Node *head = NULL;

    // Insert elements into the circular linked list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);

    // Print the circular linked list
    printf("Circular Linked List: ");
    printList(head);
    int length = Length(head);
    printf("Length = %d ", length);

    // Free the memory allocated for the circular linked list
    freeList(&head);

    return 0;
}
