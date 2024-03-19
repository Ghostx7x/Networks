#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent a term in a polynomial
typedef struct Term {
    int coeff;
    int x_exp;
    int y_exp;
    int z_exp;
    struct Term *next;
} Term;

// Function prototypes
void insertTerm(Term **poly, int coeff, int x_exp, int y_exp, int z_exp);
void displayPolynomial(Term *poly);
void evaluatePolynomial(Term *poly);
void addPolynomials(Term *poly1, Term *poly2, Term **polySum);
void clearList(Term **poly);

int main() {
    Term *POLY1 = NULL;
    Term *POLY2 = NULL;
    Term *POLYSUM = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter POLY1\n");
        printf("2. Enter POLY2\n");
        printf("3. Display POLY1\n");
        printf("4. Display POLY2\n");
        printf("5. Evaluate POLY1\n");
        printf("6. Evaluate POLY2\n");
        printf("7. Add POLY1 and POLY2\n");
        printf("8. Display POLYSUM\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clearList(&POLY1);
                printf("Enter the terms of POLY1 in the format (coeff, x_exp, y_exp, z_exp). Enter -1 -1 -1 -1 to stop:\n");
                while (1) {
                    int coeff, x_exp, y_exp, z_exp;
                    scanf("%d %d %d %d", &coeff, &x_exp, &y_exp, &z_exp);
                    if (coeff == -1 && x_exp == -1 && y_exp == -1 && z_exp == -1)
                        break;
                    insertTerm(&POLY1, coeff, x_exp, y_exp, z_exp);
                }
                break;
            case 2:
                clearList(&POLY2);
                printf("Enter the terms of POLY2 in the format (coeff, x_exp, y_exp, z_exp). Enter -1 -1 -1 -1 to stop:\n");
                while (1) {
                    int coeff, x_exp, y_exp, z_exp;
                    scanf("%d %d %d %d", &coeff, &x_exp, &y_exp, &z_exp);
                    if (coeff == -1 && x_exp == -1 && y_exp == -1 && z_exp == -1)
                        break;
                    insertTerm(&POLY2, coeff, x_exp, y_exp, z_exp);
                }
                break;
            case 3:
                printf("POLY1(x,y,z): ");
                displayPolynomial(POLY1);
                printf("\n");
                break;
            case 4:
                printf("POLY2(x,y,z): ");
                displayPolynomial(POLY2);
                printf("\n");
                break;
            case 5:
                printf("Evaluation of POLY1(x,y,z): ");
                evaluatePolynomial(POLY1);
                printf("\n");
                break;
            case 6:
                printf("Evaluation of POLY2(x,y,z): ");
                evaluatePolynomial(POLY2);
                printf("\n");
                break;
            case 7:
                clearList(&POLYSUM);
                addPolynomials(POLY1, POLY2, &POLYSUM);
                printf("POLYSUM(x,y,z): ");
                displayPolynomial(POLYSUM);
                printf("\n");
                break;
            case 8:
                printf("POLYSUM(x,y,z): ");
                displayPolynomial(POLYSUM);
                printf("\n");
                break;
            case 9:
                clearList(&POLY1);
                clearList(&POLY2);
                clearList(&POLYSUM);
                exit(0);
            default:
                printf("Invalid choice! Please enter a number between 1 and 9.\n");
        }
    }

    return 0;
}

// Function to insert a term into the polynomial
void insertTerm(Term **poly, int coeff, int x_exp, int y_exp, int z_exp) {
    Term *newTerm = (Term *)malloc(sizeof(Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newTerm->coeff = coeff;
    newTerm->x_exp = x_exp;
    newTerm->y_exp = y_exp;
    newTerm->z_exp = z_exp;
    newTerm->next = NULL;

    if (*poly == NULL) {
        *poly = newTerm;
        newTerm->next = *poly;
    } else {
        Term *temp = *poly;
        while (temp->next != *poly)
            temp = temp->next;
        temp->next = newTerm;
        newTerm->next = *poly;
    }
}

// Function to display a polynomial
void displayPolynomial(Term *poly) {
    if (poly == NULL) {
        printf("Empty polynomial.\n");
        return;
    }
    Term *temp = poly;
    do {
        printf("%dx^%dy^%dz^%d ", temp->coeff, temp->x_exp, temp->y_exp, temp->z_exp);
        if (temp->next != poly)
            printf("+ ");
        temp = temp->next;
    } while (temp != poly);
}

// Function to evaluate a polynomial for given values of x, y, and z
void evaluatePolynomial(Term *poly) {
    int x = 2; // Example value of x
    int y = 3; // Example value of y
    int z = 4; // Example value of z
    int result = 0;
    Term *temp = poly;
    do {
        result += temp->coeff * pow(x, temp->x_exp) * pow(y, temp->y_exp) * pow(z, temp->z_exp);
        temp = temp->next;
    } while (temp != poly);
    printf("%d\n", result);
}

// Function to add two polynomials
void addPolynomials(Term *poly1, Term *poly2, Term **polySum) {
    Term *temp1 = poly1;
    do {
        insertTerm(polySum, temp1->coeff, temp1->x_exp, temp1->y_exp, temp1->z_exp);
        temp1 = temp1->next;
    } while (temp1 != poly1);

    Term *temp2 = poly2;
    do {
        insertTerm(polySum, temp2->coeff, temp2->x_exp, temp2->y_exp, temp2->z_exp);
        temp2 = temp2->next;
    } while (temp2 != poly2);
}

// Function to clear a linked list
void clearList(Term **poly) {
    Term *current = *poly;
    if (*poly == NULL)
        return;

    do {
        Term *temp = current;
        current = current->next;
        free(temp);
    } while (current != *poly);

    *poly = NULL;
}
