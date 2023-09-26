#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* term = (struct Term*)malloc(sizeof(struct Term));
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

// Function to insert a term at the end of a queue
void enqueue(struct Term** rear, struct Term** front, struct Term* term) {
    if (*rear == NULL) {
        *front = term;
        *rear = term;
    } else {
        (*rear)->next = term;
        *rear = term;
    }
}

// Function to add two polynomials represented as queues
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* rear = NULL;
    struct Term* front = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent == poly2->exponent) {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                struct Term* term = createTerm(sum, poly1->exponent);
                enqueue(&rear, &front, term);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exponent > poly2->exponent) {
            struct Term* term = createTerm(poly1->coefficient, poly1->exponent);
            enqueue(&rear, &front, term);
            poly1 = poly1->next;
        } else {
            struct Term* term = createTerm(poly2->coefficient, poly2->exponent);
            enqueue(&rear, &front, term);
            poly2 = poly2->next;
        }
    }

    // Add any remaining terms from poly1 or poly2
    while (poly1 != NULL) {
        struct Term* term = createTerm(poly1->coefficient, poly1->exponent);
        enqueue(&rear, &front, term);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        struct Term* term = createTerm(poly2->coefficient, poly2->exponent);
        enqueue(&rear, &front, term);
        poly2 = poly2->next;
    }

    return front;
}

// Function to display a polynomial from its queue representation
void displayPolynomial(struct Term* poly) {
    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        if (poly->next != NULL) {
            printf("+ ");
        }
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    // Create two polynomials as queues
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    // Add terms to poly1
    enqueue(&poly1, NULL, createTerm(3, 2));
    enqueue(&poly1, NULL, createTerm(5, 1));
    enqueue(&poly1, NULL, createTerm(2, 0));

    // Add terms to poly2
    enqueue(&poly2, NULL, createTerm(2, 3));
    enqueue(&poly2, NULL, createTerm(1, 2));
    enqueue(&poly2, NULL, createTerm(7, 0));

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Term* result = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    displayPolynomial(result);

    return 0;
}
