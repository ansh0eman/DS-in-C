#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct Node* Nodeptr;

struct Node*{
    int data;
    Nodeptr left;
    Nodeptr right;
};

Nodeptr createNode(int data)

