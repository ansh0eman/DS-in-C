#include <stdio.h>
#include <stdlib.h>

// Node structure for the polynomial linked list
struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

// Function to create a new node with the given coefficient and exponent
struct Node *createNode(int coefficient, int exponent) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->coefficient = coefficient;
    node->exponent = exponent;
    node->next = NULL;
    return node;
}

// Function to insert a term into the polynomial linked list
void insertTerm(struct Node **head, int coefficient, int exponent) {
    struct Node *node = createNode(coefficient, exponent);
    if (*head == NULL || exponent > (*head)->exponent) {
        // If the list is empty or the new term has the highest exponent, insert at the beginning
        node->next = *head;
        *head = node;
    } else {
        // Otherwise, find the correct position to insert
        struct Node *current = *head;
        while (current->next != NULL && exponent < current->next->exponent) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;
    struct Node *current1 = poly1;
    struct Node *current2 = poly2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exponent == current2->exponent) {
            insertTerm(&result, current1->coefficient + current2->coefficient, current1->exponent);
            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->exponent > current2->exponent) {
            insertTerm(&result, current1->coefficient, current1->exponent);
            current1 = current1->next;
        } else {
            insertTerm(&result, current2->coefficient, current2->exponent);
            current2 = current2->next;
        }
    }

    // Copy the remaining terms from poly1 and poly2
    while (current1 != NULL) {
        insertTerm(&result, current1->coefficient, current1->exponent);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        insertTerm(&result, current2->coefficient, current2->exponent);
        current2 = current2->next;
    }

    return result;
}

// Function to multiply two polynomials
struct Node *multiplyPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;
    struct Node *current1 = poly1;

    while (current1 != NULL) {
        struct Node *current2 = poly2;
        while (current2 != NULL) {
            insertTerm(&result, current1->coefficient * current2->coefficient, current1->exponent + current2->exponent);
            current2 = current2->next;
        }
        current1 = current1->next;
    }
    struct Node* p1 = result;
    struct Node* p2 = result->next;
    
    while(p1->next!=NULL){
        if(p1->exponent == p2->exponent){
            p1->coefficient = p1->coefficient + p2->coefficient;
            struct Node* temp = p2;
            p2 = p2->next;
            p1->next = p2;
            free(temp);
        }
        else{
            p2 = p2->next;
            if(p1->exponent !=p2->exponent){
                p1=p1->next;
            }
        }
        p1=p1->next;
    }

   
    return result;
}

// Function to print the polynomial
void printPolynomial(struct Node *head) {
    if (head == NULL) {
        printf("Polynomial is empty\n");
        return;
    }

    struct Node *current = head;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);

        if (current->next != NULL) {
            printf(" + ");
        }

        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the polynomial linked list
void freePolynomial(struct Node **head) {
    struct Node *temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;

    // Insert terms into the first polynomial
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, -2, 1);
    insertTerm(&poly1, 5, 0);

    // Insert terms into the second polynomial
    insertTerm(&poly2, 2, 1);
    insertTerm(&poly2, 1, 0);

    // Add and print the result of addition
    struct Node *sum = addPolynomials(poly1, poly2);
    printf("Sum of polynomials: ");
    printPolynomial(sum);

    // Multiply and print the result of multiplication
    struct Node *product = multiplyPolynomials(poly1, poly2);
    printf("Product of polynomials: ");
    printPolynomial(product);

    // Free the memory allocated for the polynomials
    freePolynomial(&poly1);
    freePolynomial(&poly2);
    freePolynomial(&sum);
    freePolynomial(&product);

    return 0;
}
