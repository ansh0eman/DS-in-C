#include <stdio.h>
#include <stdlib.h>

struct element{
    int data;
    int priority;
};

struct priorityQ{
    struct element *arr;
    int size;
    int capacity;
};

struct priorityQ * initilizePQ(int capacity){
    struct priorityQ *pq = (struct priorityQ *)malloc(sizeof(struct priorityQ));
    pq->arr = (struct element *)malloc(sizeof(struct element)*capacity);
    pq->size =0;
    pq->capacity = capacity;
    return pq;
}

int isFull(struct priorityQ *pq){
    return pq->size == pq->capacity;
}

int isEmpty(struct priorityQ *pq){
    return pq->size ==0;
}

void pqinsert(struct priorityQ *pq, int item, int p) {
    if (isFull(pq)) {
        printf("\nQueue is FULL");
        return;
    }
    else{
        pq->arr[pq->size].data=item;
        pq->arr[pq->size].priority =p;
        pq->size++;
    }
}

int pqmindelete(struct priorityQ *pq) {
    if (isEmpty(pq)) {
        printf("\nqueue is empty");
        return -1;
    }
        int index =0;
        int p = pq->arr[index].priority;
        int minpData = pq->arr[index].data;
        for(int i=1; i<= pq->size; i++){
            if(pq->arr[i].priority<p){
                p = pq->arr[i].priority;
                minpData = pq->arr[i].data;
                index =i;
            }
        }
        for(int i=index; i< pq->size; i++){
            pq->arr[i]= pq->arr[i + 1];
        }
        pq->size--;
    return minpData;
}

void displayQ(struct priorityQ *pq) {
    int i=0;
    if (!isEmpty(pq)) {
        do {
            printf("\ndata: %d priority: %d \n", pq->arr[i].data, pq->arr[i].priority);
            i++;
        } while (i!= pq->size);
    }
}

int main(){
    struct priorityQ *pq = initilizePQ(5);
    pqinsert(pq,7,3);
    pqinsert(pq,6,2);
    displayQ(pq);
    pqinsert(pq,10,1);
    pqinsert(pq,9,4);
    pqinsert(pq,5,5);
    printf("____________");
    displayQ(pq);
    pqmindelete(pq);
    printf("______________");
    displayQ(pq);
    pqmindelete(pq);
    printf("______________");
    displayQ(pq);
}


