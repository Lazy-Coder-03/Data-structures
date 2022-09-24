// QUEUE IMPLEMENTATION BY SAYANTAN USING LINKED LIST

#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;
int lsize=0;

node *create_node(int x)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    lsize += 1;
    return newnode;
}

void enqueue(int x)
{
    node *newnode;
    if(lsize==MAX)
    {
        printf("Queue is full\n");
        return;
    }
    else if(head==NULL && tail==NULL)
    {
        newnode = create_node(x);
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode = create_node(x);
        tail->next = newnode;
        tail = newnode;
    }
}

void display()
{
    node *temp;
    if(head==NULL && tail==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    else
    {
        temp=head;
        printf("Queue is :");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void dequeue()
{
    node *temp;
    if(head==NULL && tail==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    else
    {
        temp = head;
        printf("%d is dequeued\n",temp->data);
        head=head->next;
        free(temp);
        lsize--;
    }
}

void peek()
{
    if(head==NULL && tail==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    else
    {
        printf("Front element is : %d\n",head->data);
    }
}

int main()
{
    int i = 0, r = 1, c, x;

    printf("--------------------------------------------------------\n");
    printf("LINEAR QUEUE USING LINKED_LIST BY SAYANTAN\n");
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