// Linear Queue BY SAYANTAN USING ARRAY

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int end = -1;
void enqueue(int x)
{
    if(end==MAX-1)
    {
        printf("Queue is full\n");
        return;
    }
    else if(front==-1 && end==-1)
    {
        front=0;
        end=0;
        queue[end] = x;
    }
    else
    {
        end++;
        queue[end]= x;
    }
}

void dequeue()
{
    if(front==-1 && end==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front==end)
    {
        printf("%d is dequeued",queue[front]);
        front=-1;
        end=-1;       
    }
    else
    {
        printf("%d is dequeued",queue[front]);
        front=front+1;
    }
}

void peek()
{
    if (front == -1 && end==-1)
    {
        printf("Queue is Empty\n");
        return;
    }
    else
        printf("Front Element is : %d\n", queue[front]);
}

void display()
{
    int i;
    if (front == -1 && end==-1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Stack is : ");
        for (i = front; i <=end; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int i = 0, r = 1, c, x;

    printf("--------------------------------------------------------\n");
    printf("LINEAR STACK USING ARRAY BY SAYANTAN\n");
    while (r)
    {
        printf("--------------------------------------------------------\n");
        printf("What do you want to do :- \n1) Enqueue \n2) Dequeue \n3) Peek Stack \n4) Display Queue\n5) Exit\n");
        printf("--------------------------------------------------------\n");
        printf("Enter choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter data to enqueue : ");
            scanf("%d", &x);
            enqueue(x);
            display();
            break;
        case 2:
            dequeue();
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