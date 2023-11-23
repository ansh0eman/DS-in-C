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

struct Stack
{
    struct Node * top;
};

void initStack(struct Stack * stack){
    stack->top = NULL;
}

int isEmpty(struct Stack * stack){
    return stack->top ==NULL;
}

void push(struct Stack * stack, int data ){
    struct Node * node = newNode(data);
    node->next = stack->top;
    stack->top = node;
    printf("\n%d is pushed into the stack: \n\n",node->data);
}

int pop(struct Stack * stack){
    if(isEmpty(stack)){
        printf("Stack empty\n");
        return-999;
    }
    int element = stack->top->data;
    struct Node * temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    printf("\n%d is popped out from the stack: \n\n",element);
    return element;
}

int peek(struct Stack * stack){
    if(isEmpty(stack)){
        printf("Stack Empty\n");
        return -999;
    }
    return stack->top->data;
}

void printStack(struct Stack *stack){
    if(isEmpty(stack)){
        printf("Stackempty\n");
        return;
    }
    struct Node * ptr = stack->top;
    printf("Elements of stack: \n\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr= ptr->next;
    }
    printf("\n\n");
}

void freeStack(struct Stack * stack){
    while(stack->top !=NULL){
        struct Node * temp = stack->top;
        stack->top =stack->top->next;
        free(temp);
    }
}

int main(){
    struct Stack *stack;
    initStack(stack);
    int inp, top;
    
    while(inp !=-1){
    printf("1.Push , 2.Pop, 3.Peek, 4.Print, 5.FreeStack, -1.Exit\n");
    scanf("%d",&inp);
    switch (inp)
    {
    case 1:
        printf("Enter element to push:\n");
        int data;
        scanf("%d",&data);
        push(stack,data);
        break;
    case 2:
        pop(stack);
        break;
    case 3:
        top = peek(stack);
        printf("Top element: %d",top);
        break;
    case 4:
        printStack(stack);
        break;
    case 5:
        freeStack(stack);
        printf("Stack is freed\n");
        break;
    case-1:
        return 0;
    }
}
}