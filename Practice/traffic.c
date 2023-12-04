#include <stdio.h>
#include <stdlib.h>

typedef struct Vehicle {
    int priority;
    char type;
} Vehicle;

typedef struct Traffic {
    Vehicle queue[5];
    int front;
    int rear;
} Traffic;

// Function to add a vehicle to the traffic queue
void add(Traffic *t, int p, char type) {
    if (t->rear == 4) {
        printf("Traffic queue is full. Cannot add more vehicles.\n");
    } else {
        if (t->front == -1) {
            t->front = 0;
        }

        t->rear++;
        t->queue[t->rear].priority = p;
        t->queue[t->rear].type = type;

        printf("Added %c vehicle with priority %d to the queue.\n", type, p);
    }
}

// Function to clear traffic and allow vehicles to move
void clearTraffic(Traffic *t) {
    if (t->front == -1) {
        printf("Traffic queue is empty.\n");
    } else {
        printf("%c vehicle with priority %d is allowed to move.\n", t->queue[t->front].type, t->queue[t->front].priority);

        if (t->front == t->rear) {
            t->front = t->rear = -1;
        } else {
            t->front++;
        }
    }
}

// Function to display the current traffic queue
void displayQueue(Traffic *t) {
    if (t->front == -1) {
        printf("Current traffic queue is empty.\n");
    } else {
        printf("Current traffic queue: ");
        for (int i = t->front; i <= t->rear; i++) {
            printf("%c(%d) ", t->queue[i].type, t->queue[i].priority);
        }
        printf("\n");
    }
}

int main() {
    Traffic t;
    t.front = -1;
    t.rear = -1;

    int p;
    char type;

    while (1) {
        printf("Enter priority of Vehicle and enter type (or 'q' to quit): \n");
        scanf("%d", &p);

        // Check for the termination condition
        if (p == 'q') {
            break;
        }

        // Read the type as a character
        scanf(" %c", &type);

        add(&t, p, type);
        displayQueue(&t);
        clearTraffic(&t);
        displayQueue(&t);
    }

    return 0;
}
