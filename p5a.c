#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

void push(int e);
int pop();

int a[MAX], top = -1;

int main(void) {
    char post[MAX];
    int i, op1, op2, result;

    printf("Program to evaluate postfix expression\n");
    printf("Enter the postfix expression: ");
    fgets(post, MAX, stdin);

    for (i = 0; post[i] != '\0'; i++) {
        char ch = post[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%') {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = (int)pow(op1, op2); break;
                case '%': result = op1 % op2; break;
            }
            push(result);
        } else if (ch != ' ' && ch != '\n') {
            printf("Invalid character\n");
            return 1;
        }
    }
    printf("Result of the expression is %d\n", pop());
    return 0;
}

void push(int e) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    a[++top] = e;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return 0;
    }
    return a[top--];
}



/*
#include<stdio.h> //header files
#include<ctype.h>
#include<math.h>

#define MAX 20

void push(int e); //function prototypes
int pop();
int a[MAX], top = -1; //global declarations

int main(void)
{
    char post[MAX], ch;
    int i, op1, op2, result;

    printf("Program to evaluate postfix expression\n");
    printf("Enter the postfix expression: ");
    scanf("%s", post);

    for (i = 0; post[i] != '\0'; i++)
    {
        ch = post[i]; //take one symbol from the expression
        if (isdigit(ch)) //check if it is an operand
            push(ch - '0');
        else //else if it is an operator
        {
            //pop 2 operands from the stack
            op2 = pop();
            op1 = pop();
            switch (ch) //perform the operation depending upon the operator
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            case '^':
                result = pow(op1, op2);
                break;
            case '%':
                result = op1 % op2;
                break;
            default:
                printf("Invalid character\n");
            }
            push(result); //push the result onto the stack
        }
    }
    printf("Result of the above expression is %d\n", pop());
    return 0;
}

void push(int e)
{
    ++top;
    a[top] = e;
}

int pop()
{
    int ele;
    ele = a[top];
    --top;
    return (ele);
}
*/
