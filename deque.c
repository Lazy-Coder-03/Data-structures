// Circualar deque BY SAYANTAN USING ARRAY

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int deque[MAX];
int front = -1;
int end = -1;

void enqueue_front()
{
    int x;
    if(((end+1)%MAX)==front)
    {
        printf("Queue is full\n");
        return;
    }
    else if(front==-1 && end==-1)
    {
        printf("Enter Data you want to enqueue at front : ");
        scanf("%d",&x);
        front=0;
        end=0;
        deque[front] = x;
    }
    else
    {
        printf("Enter Data you want to enqueue at front : ");
        scanf("%d",&x);
        front=(front-1)%MAX;
        deque[front] = x;
    }
}

void enqueue_end()
{
    int x;
    if(((end+1)%MAX)==front)
    {
        printf("Queue is full\n");
        return;
    }
    else if(front==-1 && end==-1)
    {
        printf("Enter Data you want to enqueue at back : ");
        scanf("%d",&x);        
        front=0;
        end=0;
        deque[end] = x;
    }
    else
    {
        printf("Enter Data you want to enqueue at back : ");
        scanf("%d",&x);
        end=(end+1)%MAX;
        deque[end] = x;
    }
}



void dequeue_front()
{
    if(front==-1 && end==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front==end)
    {
        printf("%d is dequeued\n",deque[front]);
        front=-1;
        end=-1;       
    }
    else
    {
        printf("%d is dequeued\n",deque[front]);
        front=(front+1)%MAX;
    }
}

void dequeue_end()
{
    if(front==-1 && end==-1)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(front==end)
    {
        printf("%d is dequeued\n",deque[end]);
        front=-1;
        end=-1;       
    }
    else
    {
        printf("%d is dequeued\n",deque[end]);
        end=(end-1)%MAX;
    }
}



void get_front()
{
    if (front == -1 && end==-1)
    {
        printf("Queue is Empty\n");
        return;
    }
    else
        printf("Front Element is : %d\n", deque[front]);
}

void get_end()
{
    if (front == -1 && end==-1)
    {
        printf("Queue is Empty\n");
        return;
    }
    else
        printf("Front Element is : %d\n", deque[end]);
}

void display()
{
    int i=front;
    if (front == -1 && end==-1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Stack is : ");
        while(i!=end)
        {
            printf("%d ",deque[i]);
            i=(i+1)%MAX;
        }
        printf("%d\n",deque[end]);
    }
}

int main()
{
    int i = 0, r = 1, c, x;

    printf("--------------------------------------------------------\n");
    printf("CIRCULAR DEQUE USING ARRAY BY SAYANTAN\n");
    while (r)
    {
        printf("--------------------------------------------------------\n");
        printf("What do you want to do :-\n1) Enqueue Front\n2) Enqueue Back\n3) Dequeue Front\n4) Dequeue Back\n5) Peek Front \n6) Peek End \n7) Display Deq ue\n8) Exit\n");
        printf("--------------------------------------------------------\n");
        printf("Enter choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            enqueue_front();
            display();
            break;
        case 2:
            enqueue_end();
            display();
            break;
        case 3:
            dequeue_front();
            break;
        case 4:
            dequeue_end();
            break;
        case 5:
            get_front();
            break;
        case 6:
            get_end();
            break;
        case 7:
            display();
            break;
        case 8:
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