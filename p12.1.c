#include <stdio.h>
#include <stdlib.h>

int key[20], n, m;
int *ht, ind;
int count = 0;

void insert(int new_key)
{
    ind = new_key % m;
    while (ht[ind] != -1)
    {
        printf("Collision detected at index %d. Resolving using Linear Probing\n",ind);
        ind = (ind + 1) % m;
    }
    ht[ind] = new_key;
    count++;
}

void display()
{
    int i;
    if (count == 0)
    {
        printf("\nHash Table is empty");
        return;
    }

    printf("\nHash Table contents are:\n ");
    for (i = 0; i < m; i++)
        printf("\n HT[%d] --> %d ", i, ht[i]);
}

int main()
{
    int i;
    printf("\nEnter the number of employee  records (N) : ");
    scanf("%d", &n);
    printf("\nEnter the no of memory locations (m) for hash table : ");
    scanf("%d", &m);

    ht = (int *)malloc(m * sizeof(int));
    for (i = 0; i < m; i++)
        ht[i] = -1;

    printf("\nEnter the %d Employee Records:\n",n);
    for (i = 0; i < n; i++)
        scanf("%d", &key[i]);

    for (i = 0; i < n; i++)
    {
        if (count == m)
        {
            printf("\n~~~Hash table is full. Cannot insert the record %d key~~~", i + 1);
            break;
        }
        insert(key[i]);
    }

    display();

    return 0;
}
