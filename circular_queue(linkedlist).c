//CIRCULAR QUEUE IMPLEMENTATION BY SAYANTAN USING CIRCULAR LINKED LIST

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
    else if (tail == NULL)
    {
        newnode = create_node(x);
        //head = newnode;
        tail = newnode;
        tail->next = newnode;
        // tail->next = head;
    }
    else
    {
        newnode = create_node(x);
        newnode->next = tail->next;
        tail->next = newnode;
        // tail->next = head;
        tail = newnode;
    }
    // tail->next = head;
}

void display()
{
    node *temp;
    if (tail == NULL)
    {
        printf("Queue Empty\n");
        return;
    }
    else
    {
        temp = tail->next;
        printf("Queue is : ");
        while (temp->next != tail->next)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("%d\n", temp->data);
}

void dequeue()
{
    node *temp;
    if (tail != NULL)
        temp = tail->next;
    else
    {
        printf("Queue is Empty\n");
        return;
    }
    if (temp->next == temp)
    {
        tail = NULL;
        printf("%d is Dequeued\n",temp->data);
        free(temp);
        lsize--;
    }
    else
    {
        tail->next = temp->next;
        printf("%d is Dequeued\n",temp->data);
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
        printf("Front element is : %d\n",tail->next->data);
    }
}

int main()
{
    int i = 0, r = 1, c, x;

    printf("--------------------------------------------------------\n");
    printf("CIRCULAR QUEUE USING LINKED_LIST BY SAYANTAN\n");
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
            r = 1;
            printf("Enter correct choice \n");
            exit(0);
            break;
        }
    }
}