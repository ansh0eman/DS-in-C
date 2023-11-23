#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node *newNode(int data) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the elements of a linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to concatenate two linked lists
struct Node *concatenateLists(struct Node *list1, struct Node *list2) {
    if (list1 == NULL) {
        return list2; // If the first list is empty, return the second list
    }

    struct Node *current = list1;
    while (current->next != NULL) {
        current = current->next; // Traverse to the last node of the first list
    }

    current->next = list2; // Update the next pointer to point to the head of the second list

    return list1; // Return the head of the concatenated list
}

// Function to free the memory allocated for a linked list
void freeList(struct Node *head) {
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Create the first linked list
    struct Node *list1 = newNode(1);
    list1->next = newNode(2);
    list1->next->next = newNode(3);

    // Create the second linked list
    struct Node *list2 = newNode(4);
    list2->next = newNode(5);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Concatenate the two lists
    struct Node *concatenatedList = concatenateLists(list1, list2);

    printf("Concatenated List: ");
    printList(concatenatedList);

    // Free the memory allocated for the lists
    freeList(concatenatedList);

    return 0;
}
