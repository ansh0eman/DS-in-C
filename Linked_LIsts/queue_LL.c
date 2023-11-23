#include <stdio.h>
#include <Stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

struct Node * newNode(int data){
    struct Node * newNode= (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue{
    struct Node * front;
    struct Node * rear;
};

void initQueue(struct Queue *queue){
    queue->front = queue->rear =NULL;
}

int isEmpty(struct Queue * queue){
    return queue->front ==NULL;
}

void enqueue(struct Queue * queue, int data){
    struct Node * node = newNode(data);

    if(isEmpty(queue)){
        queue->front = queue->rear = node;
    }
    else{
        queue->rear->next = node;
        queue->rear = node;
    }
    printf("%d enqueued to the queue\n", data);
}

int dequeue(struct Queue * queue){
    if(isEmpty(queue)){
        printf("Queue is Empty\n");
        return -999;
    }
    int ele = queue->front->data;
    struct Node * temp = queue->front;
    queue->front = queue->front->next;
    
    if(queue->front == NULL){ //There was only one element in Queue
        queue->rear == NULL;
    }
    free(temp);
    return ele;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Empty Queue\n");
        return -999;
    }
    return queue->front->data;
}

void printQueue(struct Queue *queue){
    if(isEmpty(queue)){
        printf("Queue Empty\n");
        return;
    }
    struct Node * ptr = queue->front;
    printf("Elements of Queue: \n\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr= ptr->next;
    }
    printf("\n\n");
}

void freeQueue(struct Queue* queue) {
    while (queue->front != NULL) {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
}
int main() {
    struct Queue * queue = (struct Queue*)malloc(sizeof(struct Queue));
    initQueue(queue);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    printQueue(queue);

    printf("Front element: %d\n", front(queue));

    printf("Dequeued element: %d\n", dequeue(queue));

    printQueue(queue);

    freeQueue(queue);

    return 0;
}

