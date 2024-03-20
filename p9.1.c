#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct term {
    int px, py, pz, cf;
    struct term *next;
} TERM;

void display_poly(TERM *head) {
    TERM *current = head;
    do {
        printf("%dx^%dy^%dz^%d", current->cf, current->px, current->py, current->pz);
        if (current->next != head) {
            printf(" + ");
        }
        current = current->next;
    } while (current != head);
    printf("\n");
}

void input_poly(TERM **head) {
    int flaginput = 1;
    do {
        TERM *newterm = (TERM *)malloc(sizeof(TERM));
        TERM *current = *head;
        printf("Enter coeff: ");
        scanf("%d", &(newterm->cf));
        printf("Enter the X pow: ");
        scanf("%d", &(newterm->px));
        printf("Enter the Y pow: ");
        scanf("%d", &(newterm->py));
        printf("Enter the Z pow: ");
        scanf("%d", &(newterm->pz));
        if (*head == NULL) {
            *head = newterm;
            newterm->next = *head;
        } else {
            while (current->next != *head) {
                current = current->next;
            }
            current->next = newterm;
            newterm->next = *head;
        }
        printf("Do you want to enter more terms? (1 for YES / 0 for NO): ");
        scanf("%d", &flaginput);
    } while (flaginput == 1);
    printf("The polynomial is: \n");
    display_poly(*head);
}

void add_poly(TERM *poly1, TERM *poly2, TERM **result) {
    TERM *current = poly1;
    do {
        TERM *newterm = (TERM *)malloc(sizeof(TERM));
        newterm->cf = current->cf;
        newterm->px = current->px;
        newterm->py = current->py;
        newterm->pz = current->pz;
        newterm->next = NULL;

        if (*result == NULL) {
            *result = newterm;
            (*result)->next = *result;
        } else {
            TERM *last = *result;
            do {
                last = last->next;
            } while (last != *result);
            last->next = newterm;
            newterm->next = *result;
        }
        current = current->next;
    } while (current != poly1);

    current = poly2;
    do {
        TERM *currentresult = *result;
        int found = 0;
        do {
            if (current->px == currentresult->px && current->py == currentresult->py && current->pz == currentresult->pz) {
                currentresult->cf += current->cf;
                found = 1;
            }
            currentresult = currentresult->next;
        } while (currentresult != *result);
        current = current->next;
        if (!found) {
            TERM *newterm = (TERM *)malloc(sizeof(TERM));
            newterm->cf = current->cf;
            newterm->px = current->px;
            newterm->py = current->py;
            newterm->pz = current->pz;

            TERM *last = *result;
            while (last->next != *result) {
                last = last->next;
            }
            last->next = newterm;
            newterm->next = *result;
        }
    } while (current != poly2);
}

void evaluate_polynomial(TERM *poly) {
    int x, y, z, sum = 0;
    printf("Enter the values of x, y, z: ");
    scanf("%d %d %d", &x, &y, &z);
    TERM *current = poly;
    do {
        sum += current->cf * pow(x, current->px) * pow(y, current->py) * pow(z, current->pz);
        current = current->next;
    } while (current != poly);
    printf("Result of polynomial evaluation: %d\n", sum);
}

int main(void) {
    int ch;
    TERM *polyhead = NULL;
    TERM *poly1head = NULL;
    TERM *poly2head = NULL;
    TERM *resulthead = NULL;
    while (1) {
        printf("Enter choice:\n");
        printf("1. Represent and Evaluate a Polynomial\n");
        printf("2. Add 2 Polynomials\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                input_poly(&polyhead);
                evaluate_polynomial(polyhead);
                break;
            case 2:
                input_poly(&poly1head);
                input_poly(&poly2head);
                add_poly(poly1head, poly2head, &resulthead);
                printf("The polynomial after addition is: \n");
                display_poly(resulthead);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}









/*

#include <stdio.h>
#include <stdlib.h>

typedef struct term {
    int px, py, pz, cf;
    struct term *next;
} TERM;

void display_poly(TERM *head) {
    TERM *current = head;
    do {
        printf("%dx^%dy^%dz^%d", current->cf, current->px, current->py, current->pz);
        if (current->next != head) {
            printf(" + ");
        }
        current = current->next;
    } while (current != head);
    printf("\n");
}

void input_poly(TERM **head) {
    int flaginput = 1;
    do {
        TERM *newterm = (TERM *)malloc(sizeof(TERM));
        TERM *current = *head;
        printf("Enter coeff \n");
        scanf("%d", &(newterm->cf));
        printf("Enter the X pow \n");
        scanf("%d", &(newterm->px));
        printf("Enter the Y pow \n");
        scanf("%d", &(newterm->py));
        printf("Enter the Z pow \n");
        scanf("%d", &(newterm->pz));
        if (*head == NULL) {
            *head = newterm;
            newterm->next = *head;
        } else {
            while (current->next != *head) {
                current = current->next;
            }
            current->next = newterm;
            newterm->next = *head;
        }
        printf("Do you want to enter more terms (1 for YES / 0 for NO) \n");
        scanf("%d", &flaginput);
    } while (flaginput == 1);
    printf("The polynomial is: \n");
    display_poly(*head);
}

void add_poly(TERM *poly1, TERM *poly2, TERM **result) {
    TERM *current = poly1;
    do {
        TERM *newterm = (TERM *)malloc(sizeof(TERM));
        newterm->cf = current->cf;
        newterm->px = current->px;
        newterm->py = current->py;
        newterm->pz = current->pz;
        newterm->next = NULL;

        if (*result == NULL) {
            *result = newterm;
            (*result)->next = *result;
        } else {
            TERM *last = *result;
            do {
                last = last->next;
            } while (last != *result);
            last->next = newterm;
            newterm->next = *result;
        }
        current = current->next;
    } while (current != poly1);

    current = poly2;
    do {
        TERM *currentresult = *result;
        int found = 0;
        do {
            if (current->px == currentresult->px && current->py == currentresult->py && current->pz == currentresult->pz) {
                currentresult->cf += current->cf;
                found = 1;
            }
            currentresult = currentresult->next;
        } while (currentresult != *result);
        current = current->next;
        if (!found) {
            TERM *newterm = (TERM *)malloc(sizeof(TERM));
            newterm->cf = current->cf;
            newterm->px = current->px;
            newterm->py = current->py;
            newterm->pz = current->pz;

            TERM *last = *result;
            while (last->next != *result) {
                last = last->next;
            }
            last->next = newterm;
            newterm->next = *result;
        }
    } while (current != poly2);
}

int main() {
    int ch;
    TERM *polyhead = NULL;
    TERM *poly1head = NULL;
    TERM *poly2head = NULL;
    TERM *resulthead = NULL;
    while (1) {
        printf("Enter choice \n");
        printf("1. Represent Polynomial \n");
        printf("2. Add 2 Polynomials \n");
        printf("3. Exit\n");
        printf("Enter your choice \n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                input_poly(&polyhead);
                break;
            case 2:
                input_poly(&poly1head);
                input_poly(&poly2head);
                add_poly(poly1head, poly2head, &resulthead);
                printf("The polynomial after addition is: \n");
                display_poly(resulthead);
            case 3:
                exit(0);
            default:
                printf("Invalid Choice \n");
        }
    }
    return 0;
}
*/