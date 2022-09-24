// STACK IMPLEMENTATION BY SAYANTAN USING ARRAY

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int x;
    if (top < MAX - 1)
    {
        printf("Enter data you want to Push : ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
    else
        printf("Stack Overflow\n");
}

void pop()
{
    int x;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    else
    {
        x = stack[top];
        printf("%d is Popped\n", x);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }
    else
        printf("Top Element is : %d\n", stack[top]);
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack is : ");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int i = 0, r = 1, c, x;

    printf("--------------------------------------------------------\n");
    printf("STACK USING ARRAY BY SAYANTAN\n");
    while (r)
    {
        printf("--------------------------------------------------------\n");
        printf("What do you want to do :- \n1) Push data \n2) Pop data \n3) Peek Stack \n4) Display Stack\n5) Exit\n");
        printf("--------------------------------------------------------\n");
        printf("Enter choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            push();
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            r = 0;
            exit(0);
            break;
        default:
            r = 0;
            exit(0);
            break;
        }
    }
}
