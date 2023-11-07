#include <stdio.h>
#include <stdlib.h>

struct CQ {
    int front, rear, size;
    int capacity;
    int *arr;
};

void initializeQ(struct CQ *q, int capacity) {
    q->capacity = capacity;
    q->arr = (int *)malloc(sizeof(int) * capacity);
    if (!q->arr) {
        printf("Failed!");
        exit(0);
    }
    q->front = q->rear = -1;
    q->size = 0;
}

int isFull(struct CQ *q) {
    return (q->front == (q->rear + 1) % q->capacity); // OR q->size == q->capacity
}

int isEmpty(struct CQ *q) {
    return (q->front == -1 && q->rear == -1); // OR q->size =0
}

void enQueue(struct CQ *q, int item) {
    if (isFull(q)) {
        printf("\nQueue is FULL");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->capacity;
    }
    q->arr[q->rear] = item;
    q->size++;
}

int deQueue(struct CQ *q) {
    if (isEmpty(q)) {
        printf("\nqueue is empty");
        return -1;
    }
    int item = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->capacity;
    }
    q->size--;
    printf("\n%d\n", item);
    return item;
}

void displayCQ(struct CQ *q) {
    int ptr = q->front;
    if (!isEmpty(q)) {
        do {
            printf("%d ", q->arr[ptr]);
            ptr = (ptr + 1) % q->capacity;
        } while (ptr != q->rear);
        printf("%d", q->arr[q->rear]);
    }
}

int size(struct CQ *q) {
    printf("%d\n", q->size);
    return (q->size);
}

void freeCQ(struct CQ *q) {
    free(q->arr);
    free(q);
}

int main() {
    struct CQ *q = (struct CQ *)malloc(sizeof(struct CQ));
    if (!q) {
        printf("Failed!");
        exit(1);
    }

    initializeQ(q, 3);
    enQueue(q, 5);
    enQueue(q, 7);
    size(q);
    displayCQ(q);
    deQueue(q);
    size(q);
    enQueue(q, 10);
    enQueue(q, 3);
    size(q);
    displayCQ(q);
    enQueue(q, 2);
    enQueue(q, 8);
    size(q);
    displayCQ(q);
    deQueue(q);
    size(q);
    displayCQ(q);

    freeCQ(q);

    return 0;
}
