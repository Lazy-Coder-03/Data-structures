// STACK IMPLEMENTATION BY SAYANTAN USING LINKED LIST

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct node
{
    int data;
    struct node *next;
} node;

node *top = NULL;
int lsize=0;

node *create_node(int x)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    lsize += 1;
    return newnode;
}

void push()
{
    if (lsize < MAX)
    {
        int x;
        printf("Enter data you want to Push : ");
        scanf("%d", &x);
        node *newnode = create_node(x);
        newnode->next = top;
        top = newnode;
    }
    else
        printf("Stack Overflow\n");
}

void pop()
{
    node *temp;
    if (top == NULL)
        printf("Stack Underflow\n");
    else
    {
        temp = top;
        top = top->next;
        printf("%d is Popped\n", temp->data);
        free(temp);
        lsize--;
    }
}

void display()
{
    node *temp = top;
    if (top != NULL)
    {
        printf("Stack is : ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else
        printf("Stack is Empty\n");
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack Empty\n");
        return;
    }
    else
    {
        printf("Top element = %d\n", top->data);
    }
}

int main()
{
    int i = 0, r = 1, c, x;

    printf("--------------------------------------------------------\n");
    printf("STACK USING LINKED LIST BY SAYANTAN\n");
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