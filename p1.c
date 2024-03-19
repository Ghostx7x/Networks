#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

struct day
{
    char *dayName;
    int d, m, y;
    char *activity_description;
};

void create(struct day *calendar)
{
    char *dayNames[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for (int i = 0; i < 7; i++)
    {
        calendar[i].dayName = strdup(dayNames[i]);
        calendar[i].activity_description = (char *)malloc(MAX * sizeof(char));
    }
}

void read(struct day *calendar)
{
    for (int i = 0; i < 7; i++)
    {
        printf("Enter date for %s in DD/MM/YYYY: ", calendar[i].dayName);
        scanf("%d%d%d", &calendar[i].d, &calendar[i].m, &calendar[i].y);
        while(getchar() != '\n'); // Consume newline character left by scanf
        printf("Enter activity for %s : ", calendar[i].dayName);
        fgets(calendar[i].activity_description, MAX, stdin);
        // Remove trailing newline from fgets
        calendar[i].activity_description[strcspn(calendar[i].activity_description, "\n")] = '\0';
    }
}

void display(struct day *calendar)
{
    printf("%-10s%-12s%-30s\n", "Day", "Date", "Activity");
    for (int i = 0; i < 7; i++)
    {
        printf("%-10s%02d/%02d/%d   %-30s\n", calendar[i].dayName, calendar[i].d, calendar[i].m, calendar[i].y, calendar[i].activity_description);
    }
}

int main(void)
{
    struct day *calendar = (struct day *)malloc(7 * sizeof(struct day));
    if (calendar == NULL)
    {
        fprintf(stderr, "Memory Allocation Failed");
        return 1;
    }
    create(calendar);
    read(calendar);
    display(calendar);
    for (int i = 0; i < 7; i++)
    {
        free(calendar[i].dayName);
        free(calendar[i].activity_description);
    }
    free(calendar);
    return 0;
}