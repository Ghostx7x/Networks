#include <stdio.h>

void stringmatch(char str[], char pat[], char rep[]) 
{
    char ans[100];
    int i = 0, j = 0;

    while (str[i] != '\0') 
    {
        int k = 0;
        int match = 1;

        while (pat[k] != '\0') 
        {
            if (str[i + k] != pat[k]) 
            {
                match = 0;
                break;
            }
            k++;
        }

        if (match) 
        {
            k = 0;

            while (rep[k] != '\0')
                ans[j++] = rep[k++];

            while (str[i + k] != '\0' && ((str[i + k] < 'A') || (str[i + k] > 'Z' && str[i + k] < 'a') || (str[i + k] > 'z'))) 
            {
                ans[j++] = str[i + k];
                k++;
            }

            if (str[i + k] != '\0' && str[i + k] != ' ')
                ans[j++] = ' ';

            i += k;
        } else
            ans[j++] = str[i++];
    }

    ans[j] = '\0';

    printf("\nThe resultant string is:\n%s\n", ans);
}

int main(void) {
    char str[100], pat[50], rep[50];

    printf("Enter a main string:\n");
    scanf("%99[^\n]", str);
    printf("Enter a pattern string:\n");
    scanf("%49s", pat);
    printf("Enter a replace string:\n");
    scanf("%49s", rep);
    stringmatch(str, pat, rep);
}
