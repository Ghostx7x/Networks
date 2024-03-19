#include<stdio.h>

int count = 0;

void tower(int n, char s, char t, char d)
{
    if (n == 1)
    {
        printf("Move disc 1 from %c to %c\n", s, d);
        count++;
        return;
    }
    tower(n - 1, s, d, t);
    printf("Move disc %d from %c to %c\n", n, s, d);
    count++;
    tower(n - 1, t, s, d);
}

int main()
{
    int n;
    printf("Enter the number of discs\n");
    scanf("%d", &n);

    tower(n, 'A', 'B', 'C');

    printf("Total number of moves = %d\n", count);

    return 0;
}