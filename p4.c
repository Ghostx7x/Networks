#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_SIZE 50

char stack[MAX_SIZE];
int top = -1;

void push(char ele) {
    if (top == MAX_SIZE - 1) {
        printf("Error: Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = ele;
}

char pop() {
    if (top == -1) {
        printf("Error: Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[top--];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^':
            return 3;
        default:
            return -1; // Invalid operator
    }
}

int main(void) {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    int i, j = 0;

    printf("Enter a valid infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isdigit(ch) || isalpha(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            if (top != -1 && stack[top] == '(')
                pop(); // Discard the '('
            else {
                printf("Error: Mismatched parentheses\n");
                exit(EXIT_FAILURE);
            }
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^') {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        } else if (ch != ' ' && ch != '\n') {
            printf("Error: Invalid character in infix expression\n");
            exit(EXIT_FAILURE);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("The postfix expression is: %s\n", postfix);

    return 0;
}


/*
#include<stdio.h>
#include<ctype.h>

int precedence(char);
char pop();
void push(char);

char postfix[50], infix[50], s[50];
int top = -1;

int main(void) {
    int i, j = 0;
    char ch, elem;

    printf("Enter a valid infix expression\n");
    gets(infix);

    push('#');

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch))
            postfix[j++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')') {
            while (s[top] != '(')
                postfix[j++] = pop();
            elem = pop();
        } else {
            while (precedence(s[top]) >= precedence(ch)) {
                if ((ch == '^') && (s[top] == '^'))
                    break;
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (s[top] != '#')
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("The postfix expression is %s\n", postfix);
}

int precedence(char e) {
    switch (e) {
        case '#':
            return (-1);
            break;
        case '(':
            return (0);
            break;
        case '+':
        case '-':
            return (1);
            break;
        case '%':
        case '*':
        case '/':
            return (2);
            break;
        case '^':
            return (3);
            break;
        default:
            printf("Error \n");
        return -1;
    }
}

void push(char ele) {
    ++top;
    s[top] = ele;
}

char pop() {
    char e;
    e = s[top];
    --top;
    return e;
}
*/