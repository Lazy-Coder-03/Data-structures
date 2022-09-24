#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STACKSIZE 100

char stack[STACKSIZE];
int top = -1;

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        // printf("Stack is : ");
        for (i = top; i > 0; i--)
        {
            printf("%c ", stack[i]);
            // printf("|\n");
            // printf("v\n");
        }
        printf("%c\n", stack[i]);
    }
}

void printarr(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void push(char x)
{
    // int x;
    if (top < STACKSIZE - 1)
    {
        top++;
        stack[top] = x;
    }
    else
        printf("Stack Overflow\n");
}

char pop()
{
    char item;

    if (top == -1)
    {
        printf("stack under flow: invalid infix expression");
        return '$';
    }
    else
    {
        item = stack[top];
        top--;
        return (item);
    }
}

int peek()
{
    if (top != -1)
        return stack[top];
    else
    {
        //printf("Stack empty\n");
        return '$';
    }
}

int prec(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return -1;
}

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int infixTopostfix(char *exp)
{
    int i, k;

    for (i = 0, k = -1; exp[i] != '\0'; i++)
    {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
        {
            push(exp[i]);
            display(stack);
        }
        else if (exp[i] == ')')
        {
            while (top != -1 && peek(stack) != '(')
            {
                exp[++k] = pop(stack);
                display(stack);
            }
            if (top != -1 && peek(stack) != '(')
                return -1;
            else
                pop(stack);
                display(stack);
        }
        else
        {
            while (top != -1 && prec(exp[i]) <= prec(peek(stack)))
            {
                exp[++k] = pop();
            }
            push(exp[i]);
            display(stack);
        }
    }
    while (top != -1)
        exp[++k] = pop(stack);
    exp[++k] = '\0';
    printf("%s ", exp);
}

int main()
{
    char x[] = "A+B*C-D/(E+F)*G";
    infixTopostfix(x);
    //display(stack);
}