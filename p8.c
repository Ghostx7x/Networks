#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {
    char SSN[20];
    char Name[50];
    char Dept[50];
    char Designation[50];
    float Sal;
    char PhNo[15];
    struct Employee *prev;
    struct Employee *next;
} Employee;

Employee *head = NULL;

void main_menu();
void create_list();
void display();
void insert_end();
void del_end();
void insert_front();
void del_front();
void double_ended_queue();

int main() {
    main_menu();
    return 0;
}

void main_menu() {
    int choice;
    while (1) {
        printf("\nDOUBLY LINKED LIST MENU\n");
        printf("1. Create DLL of N Employees Data (End Insertion)\n");
        printf("2. Display DLL and Count Nodes\n");
        printf("3. Insert at End of DLL\n");
        printf("4. Delete from End of DLL\n");
        printf("5. Insert at Front of DLL\n");
        printf("6. Delete from Front of DLL\n");
        printf("7. Use DLL as Double Ended Queue\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_list();
                break;
            case 2:
                display();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                del_end();
                break;
            case 5:
                insert_front();
                break;
            case 6:
                del_front();
                break;
            case 7:
                double_ended_queue();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void create_list() {
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);

    Employee *temp, *newNode;
    for (int i = 0; i < n; i++) {
        newNode = (Employee *)malloc(sizeof(Employee));
        printf("Enter SSN, Name, Dept, Designation, Salary, and Phone Number for Employee %d: ", i + 1);
        scanf("%s %s %s %s %f %s", 
            newNode->SSN, newNode->Name, newNode->Dept, newNode->Designation, &newNode->Sal, newNode->PhNo);

        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void display() {
    Employee *temp = head;
    int count = 0;

    printf("\nDoubly Linked List of Employees:\n");
    while (temp != NULL) {
        printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, Phone: %s\n", 
            temp->SSN, temp->Name, temp->Dept, temp->Designation, temp->Sal, temp->PhNo);
        temp = temp->next;
        count++;
    }

    printf("Number of nodes: %d\n", count);
}

void insert_end() {
    Employee *newNode = (Employee *)malloc(sizeof(Employee));
    printf("Enter SSN, Name, Dept, Designation, Salary, and Phone Number for the new employee: ");
    scanf("%s %s %s %s %f %s", 
        newNode->SSN, newNode->Name, newNode->Dept, newNode->Designation, &newNode->Sal, newNode->PhNo);
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        Employee *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void del_end() {
    if (head == NULL) {
        printf("DLL is empty.\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    Employee *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    printf("Last node deleted.\n");
}

void insert_front() {
    Employee *newNode = (Employee *)malloc(sizeof(Employee));
    printf("Enter SSN, Name, Dept, Designation, Salary, and Phone Number for the new employee: ");
    scanf("%s %s %s %s %f %s", 
        newNode->SSN, newNode->Name, newNode->Dept, newNode->Designation, &newNode->Sal, newNode->PhNo);
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void del_front() {
    if (head == NULL) {
        printf("DLL is empty.\n");
        return;
    }

    Employee *temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
    printf("First node deleted.\n");
}

void double_ended_queue() {
    int choice;
    while (1) {
        printf("\nDOUBLE ENDED QUEUE MENU\n");
        printf("1. Insert at End\n");
        printf("2. Delete from Front\n");
        printf("3. Display DLL and Count Nodes\n");
        printf("4. Exit from Double Ended Queue menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_end();
                break;
            case 2:
                del_front();
                break;
            case 3:
                display();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
