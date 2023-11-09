#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    int processID;
    int priority;
    struct Process* next;
};

// Function to create a new process node
struct Process* createProcess(int processID, int priority) {
    struct Process* newProcess = (struct Process*)malloc(sizeof(struct Process));
    newProcess->processID = processID;
    newProcess->priority = priority;
    newProcess->next = NULL;
    return newProcess;
}

// Function to insert a new process into the priority queue based on its priority
void insertProcess(struct Process** head, int processID, int priority) {
    struct Process* newProcess = createProcess(processID, priority);

    if (*head == NULL || priority < (*head)->priority) {
        newProcess->next = *head;
        *head = newProcess;
    } else {
        struct Process* current = *head;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        newProcess->next = current->next;
        current->next = newProcess;
    }
}

// Function to remove the process with the highest priority from the queue
void deleteProcess(struct Process** head) {
    if (*head == NULL) {
        printf("Queue is empty. No process to delete.\n");
    } else {
        struct Process* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Function to display the processes in the queue
void displayQueue(struct Process* head) {
    printf("Process Queue: ");
    while (head != NULL) {
        printf("(%d, %d) -> ", head->processID, head->priority);
        head = head->next;
    }
    printf("NULL\n");
}

// Driver code to test the priority queue
int main() {
    struct Process* head = NULL;

    // Insert processes with their priorities into the queue
    insertProcess(&head, 1, 3);
    insertProcess(&head, 2, 1);
    insertProcess(&head, 3, 2);

    // Display the initial queue
    displayQueue(head);

    // Delete a process and display the updated queue
    deleteProcess(&head);
    displayQueue(head);

    return 0;
}
