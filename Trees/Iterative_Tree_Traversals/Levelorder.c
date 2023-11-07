#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Structure for a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Node** array;
};

// Function to create a queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (struct Node**)malloc(queue->capacity * sizeof(struct Node*));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to enqueue a node to the queue
void enqueue(struct Queue* queue, struct Node* item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Function to dequeue a node from the queue
struct Node* dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return NULL;
    struct Node* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to create a new binary tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to perform level order traversal
void levelOrder(struct Node* root) {
    struct Queue* queue = createQueue(100);

    if (root == NULL)
        return;

    enqueue(queue, root);

    while (!isEmpty(queue)) {
        struct Node* current = dequeue(queue);
        printf("%d ", current->data);

        if (current->left)
            enqueue(queue, current->left);
        if (current->right)
            enqueue(queue, current->right);
    }
}

// Main function
int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
