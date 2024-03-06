#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct employee
{
    char empName[20];
    int empId;
} EMP;

int hashTable[MAX];

EMP emp[MAX];

void initializeHashTable()
{
    for (int i = 0; i < MAX; i++)
    {
        emp[i].empId = 0;
        strcpy(emp[i].empName, "\0");
        hashTable[i] = -1;
    }
}

void display(int ch)
{
    int i = 0;
    printf("HASH TABLE IS: \n");
    printf("HTKey\t\tEmpName\t\tEmpID \n");
    if (ch == 1)
    {
        for (i = 0; i < MAX; i++)
        {
            printf("%d\t\t%s\t\t%d \n", i, emp[i].empName, emp[i].empId);
        }
    }
    else
    {
        for (i = 0; i < MAX; i++)
        {
            if (hashTable[i] != -1)
                printf("%d\t\t%s\t\t%d \n", i, emp[i].empName, emp[i].empId);
        }
    }
}

int getKey(int num)
{
    printf("Generated Key %d. \n", num % MAX);
    return num % MAX;
}

void insert_handler_probing(char name[], int key, int id)
{
    if (hashTable[key] == -1)
    {
        hashTable[key] = id;
        printf("No Collisions Detected. Key = %d \n", key);
        emp[key].empId = id;
        strcpy(emp[key].empName, name);
    }
    else
    {
        printf("Collision Detected at key %d! Using Linear Probing to Solve the issue \n", key);
        int i = key, flag = 0;
        int updatedKey = 0;
        while (i < MAX)
        {
            if (hashTable[i] == -1)
            {
                updatedKey = i;
                flag = 1;
                break;
            }
            i++;
        }
        if (flag != 1)
        {
            for (i = 0; i < key; i++)
            {
                if (hashTable[i] == -1)
                {
                    updatedKey = i;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag != 1)
        {
            printf("Hash Table is Full! Cannot Insert! \n");
        }
        else
        {
            printf("Collision Resolved Using Linear Probing. Updated key = %d \n", updatedKey);
            hashTable[updatedKey] = id;
            emp[updatedKey].empId = id;
            strcpy(emp[updatedKey].empName, name);
        }
    }
}

int main(void)
{
    int ch;
    int numEmployees;
    int displaych;
    initializeHashTable();
    while (1)
    {
        printf("Hash Table Operations! \n");
        printf("1. Insert Data \n");
        printf("2. Display \n");
        printf("3. Clear Hash Table \n");
        printf("4. Exit \n");
        printf("Enter your choice \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter number of employees \n");
            scanf("%d", &numEmployees);
            for (int i = 0; i < numEmployees; i++)
            {
                int empid;
                char empName[20];
                printf("Enter employee ID (4-Ditit): \n");
                scanf("%d", &empid);
                printf("Enter employee name: \n");
                scanf("%s", empName);
                int key = getKey(empid);
                insert_handler_probing(empName, key, empid);
            }
            break;

        case 2:
            printf("Full Display (1) or Filled Only? (2)? \n");
            scanf("%d", &displaych);
            display(displaych);
            break;

        case 3:
            initializeHashTable();
            printf("Hash Table Cleared! \n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid Choice \n");
        }
    }
    return 0;
}
