#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int contains(struct Node* head, int data) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1; // true
        }
        current = current->next;
    }
    return 0; // false
}

struct Node* unionLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    while (list1 != NULL) {
        insertAtEnd(&result, list1->data);
        list1 = list1->next;
    }
    while (list2 != NULL) {
        if (!contains(result, list2->data)) {
            insertAtEnd(&result, list2->data);
        }
        list2 = list2->next;
    }
    return result;
}

struct Node* intersectionLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    while (list1 != NULL) {
        if (contains(list2, list1->data)) {
            insertAtEnd(&result, list1->data);
        }
        list1 = list1->next;
    }
    return result;
}

void freeList(struct Node* head) {
    while(head!=NULL){
        struct Node* temp = head;
        head=head->next;
        free(temp);
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Populate lists
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 2);
    insertAtEnd(&list1, 3);

    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 3);
    insertAtEnd(&list2, 4);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Union
    struct Node* unionResult = unionLists(list1, list2);
    printf("Union: ");
    printList(unionResult);

    // Intersection
    struct Node* intersectionResult = intersectionLists(list1, list2);
    printf("Intersection: ");
    printList(intersectionResult);

    // Free memory
    freeList(list1);
    freeList(list2);
    freeList(unionResult);
    freeList(intersectionResult);

    return 0;
}
