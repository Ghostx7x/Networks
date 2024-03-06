#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char usn[20], name[20], branch[10], phno[10];
    int sem;
    struct node *link;
} NODE;

NODE *start = NULL;

void main_menu();
void create_list();
void insert_front();
void display();
void insert_end();
void del_front();
void del_end();
void stack();

int main(void) {
    main_menu();
}

void main_menu() {
    int ch;
    while (1) {
        printf("\nSINGLY LINKED LIST IMPLEMENTATION\n");
        printf("1. CREATE LIST\n");
        printf("2. INSERTION AND DELETION FROM FRONT (STACK)\n");
        printf("3. INSERT END\n");
        printf("4. DELETE END\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
                create_list();
                break;
            case 2: 
                stack();
                break;
            case 3: 
                insert_end();
                break;
            case 4: 
                del_end();
                break;
            case 5: 
                display();
                break;
            case 6: 
                exit(0);
            default: 
                printf("INVALID CHOICE\n");
        }
    }
}

void create_list() {
    NODE *newnode = NULL;
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        insert_front();
}

void display() {
    NODE *curptr = NULL;
    int count = 0;
    if (start == NULL)
        printf("\nLIST EMPTY\n");
    else {
        curptr = start;
        printf("\nUSN\tNAME\tBRANCH\tSEM\tPHONENUMBER\n");
        while (curptr != NULL) {
            printf("%s\t%s\t%s\t%d\t%s\n", curptr->usn, curptr->name, curptr->branch, curptr->sem, curptr->phno);
            curptr = curptr->link;
            count++;
        }
    }
    printf("\nNUMBER OF NODES= %d\n", count);
}

void stack() {
    int ch;
    while (1) {
        printf("\nSTACK IMPLEMENTATION\n");
        printf("1. Insert front\n");
        printf("2. Delete front\n");
        printf("3. Display\n");
        printf("4. Exit from stack menu\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
                insert_front();
                break;
            case 2: 
                del_front();
                break;
            case 3: 
                display();
                break;
            case 4: 
                main_menu();
                break;
            default: 
                printf("INVALID CHOICE\n");
        }
    }
}

void insert_front() {
    NODE *newnode = NULL;
    newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter USN: ");
    scanf("%s", newnode->usn);
    printf("Enter name and branch: ");
    scanf("%s%s", newnode->name, newnode->branch);
    printf("Enter semester: ");
    scanf("%d", &newnode->sem);
    printf("Enter phone number: ");
    scanf("%s", newnode->phno);
    newnode->link = start;
    start = newnode;
}

void del_front() {
    NODE *curptr = NULL;
    if (start == NULL)
        printf("\nLIST EMPTY\n");
    else {
        curptr = start;
        start = start->link;
        printf("The deleted information is\n");
        printf("USN\tNAME\tBRANCH\tSEM\tPHONENUMBER\n");
        printf("%s\t%s\t%s\t%d\t%s\n", curptr->usn, curptr->name, curptr->branch, curptr->sem, curptr->phno);
        free(curptr);
    }
}

void insert_end() {
    NODE *curptr, *newnode = NULL;
    newnode = (NODE*)malloc(sizeof(NODE));
    printf("Enter USN: ");
    scanf("%s", newnode->usn);
    printf("Enter name and branch: ");
    scanf("%s%s", newnode->name, newnode->branch);
    printf("Enter semester: ");
    scanf("%d", &newnode->sem);
    printf("Enter phone number: ");
    scanf("%s", newnode->phno);
    if (start == NULL) {
        newnode->link = start;
        start = newnode;
    } else {
        curptr = start;
        while (curptr->link != NULL)
            curptr = curptr->link;
        newnode->link = NULL;
        curptr->link = newnode;
    }
}

void del_end() {
    NODE *curptr = NULL, *nextcur = NULL;
    if (start == NULL)
        printf("\nLIST EMPTY\n");
    else if (start->link == NULL) {
        free(start);
        start = NULL;
    } else {
        curptr = start;
        nextcur = curptr;
        while (curptr->link != NULL) {
            nextcur = curptr;
            curptr = curptr->link;
        }
        nextcur->link = NULL;
        free(curptr);
    }
}


/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char USN[20];
    char Name[50];
    char Programme[20];
    int Sem;
    long long int PhNo;
    struct Student* next;
} Student;

void createSLL(Student** head);
void displaySLL(Student* head);
int countNodes(Student* head);
void insertEnd(Student** head);
void deleteEnd(Student** head);
void insertFront(Student** head);
void deleteFront(Student** head);

int main() {
    Student* head = NULL;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Create a SLL of Students Data\n");
        printf("2. Display the status of SLL and count the number of nodes\n");
        printf("3. Insert at the end of SLL\n");
        printf("4. Delete at the end of SLL\n");
        printf("5. Insert at the front of SLL (Demonstration of stack)\n");
        printf("6. Delete at the front of SLL (Demonstration of stack)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createSLL(&head);
                break;
            case 2:
                displaySLL(head);
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 3:
                insertEnd(&head);
                break;
            case 4:
                deleteEnd(&head);
                break;
            case 5:
                insertFront(&head);
                break;
            case 6:
                deleteFront(&head);
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while(choice != 7);

    return 0;
}

void createSLL(Student** head) {
    int n, i;
    Student* newNode, *temp;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        newNode = (Student*)malloc(sizeof(Student));
        if(newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        printf("Enter details for student %d:\n", i + 1);
        printf("USN: ");
        scanf("%s", newNode->USN);
        printf("Name: ");
        scanf("%s", newNode->Name);
        printf("Programme: ");
        scanf("%s", newNode->Programme);
        printf("Semester: ");
        scanf("%d", &newNode->Sem);
        printf("Phone Number: ");
        scanf("%lld", &newNode->PhNo);

        newNode->next = NULL;

        if(*head == NULL) {
            *head = newNode;
        } else {
            temp = *head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void displaySLL(Student* head) {
    Student* temp = head;

    if(temp == NULL) {
        printf("The list is empty.\n");
    } else {
        printf("Student Data:\n");
        while(temp != NULL) {
            printf("USN: %s, Name: %s, Programme: %s, Sem: %d, PhNo: %lld\n",
                temp->USN, temp->Name, temp->Programme, temp->Sem, temp->PhNo);
            temp = temp->next;
        }
    }
}

int countNodes(Student* head) {
    int count = 0;
    Student* temp = head;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

void insertEnd(Student** head) {
    Student* newNode, *temp = *head;

    newNode = (Student*)malloc(sizeof(Student));
    if(newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter details for the new student:\n");
    printf("USN: ");
    scanf("%s", newNode->USN);
    printf("Name: ");
    scanf("%s", newNode->Name);
    printf("Programme: ");
    scanf("%s", newNode->Programme);
    printf("Semester: ");
    scanf("%d", &newNode->Sem);
    printf("Phone Number: ");
    scanf("%lld", &newNode->PhNo);

    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
    } else {
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteEnd(Student** head) {
    Student* temp = *head;
    Student* prev = NULL;

    if(*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    if(prev == NULL) {
        free(temp);
        *head = NULL;
    } else {
        prev->next = NULL;
        free(temp);
    }

    printf("Last node deleted successfully.\n");
}

void insertFront(Student** head) {
    Student* newNode;

    newNode = (Student*)malloc(sizeof(Student));
    if(newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter details for the new student:\n");
    printf("USN: ");
    scanf("%s", newNode->USN);
    printf("Name: ");
    scanf("%s", newNode->Name);
    printf("Programme: ");
    scanf("%s", newNode->Programme);
    printf("Semester: ");
    scanf("%d", &newNode->Sem);
    printf("Phone Number: ");
    scanf("%lld", &newNode->PhNo);

    newNode->next = *head;
    *head = newNode;
}

void deleteFront(Student** head) {
    Student* temp;

    if(*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;
    free(temp);

    printf("First node deleted successfully.\n");
}
*/