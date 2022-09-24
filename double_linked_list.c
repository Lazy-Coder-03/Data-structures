// DOUBLE_LINK-lINKED-LIST IMPLEMENTATION BY SAYANTAN
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;

node *head = NULL;
node *tail = NULL;
int lsize = 0;

node *create_node(int x)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;
    lsize += 1;
    return newnode;
}

void ins_beg(int x)
{
    node *newnode = create_node(x);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}

void ins_end(int x)
{
    node *newnode = create_node(x);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void ins_pos(int x, int n)
{
    int i = 1;
    if (n < 1 || n > lsize)
    {
        printf("Invalid position\n");
        return;
    }
    else if (n == 1 || head == NULL)
        ins_beg(x);
    else if (n == lsize || head == NULL)
        ins_end(x);
    else
    {
        node *newnode = create_node(x);
        node *temp = head;
        while (i < n - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void del_beg()
{
    node *temp;
    if (head == NULL)
        printf("List Empty\n");
    else
    {
        lsize--;
        temp = head;
        head = head->next;
        head->prev = NULL;
        printf("%d is deleted\n", temp->data);
        free(temp);
    }
}

void del_end()
{
    node *temp;
    if (head == NULL)
        printf("List Empty\n");
    else
    {
        lsize--;
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        printf("%d is deleted\n", temp->data);
        free(temp);
    }
}

void del_pos(int pos)
{
    node *temp;
    int i = 1;
    if (head == NULL)
    {
        printf("List Empty\n");
        return;
    }
    else if (pos < 1 || pos > lsize)
        printf("Invalid position\n");
    else if (pos == 1)
        del_beg();
    else if (pos == lsize)
        del_end();
    else
    {
        temp = head;
        lsize--;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        printf("%d is deleted\n", temp->data);
        free(temp);
    }
}

void delete_list()
{
    struct node *temp;

    while (head != NULL)
    {
        lsize -= 1;
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Sucessfully deleted all elements in the list...\n");
}

int search(int key)
{
    int index;
    node *current;
    index = 1;
    current = head;
    while (current != NULL && current->data != key)
    {
        index++;
        current = current->next;
    }
    if (current != NULL)
        return index;
    else
        return -1;
}

void del_num(int key)
{
    int pos;
    pos = search(key);

    if (pos == -1)
        printf("Element not present\n");
    else
    {
        del_pos(pos);
    }
}

void reverse_list()
{
    node *current, *temp;
    if (head == NULL)
        printf("List Empty\n");
    else
    {
        current = head;
        while (current != NULL)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        temp = head;
        head = tail;
        tail = temp;
    }
}

void display()
{
    node *temp = head;
    if (head != NULL)
    {
        printf("List is : ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
        // debuging
        // printf("Head = %d\n", head->data);
        // printf("Tail = %d\n", tail->data);
        // printf("list Size = %d\n", lsize);
    }
    else
        printf("List Empty \n");
}

int main()
{

    int n, i, x, c, p, del_c, pos;
    // char cont='y';
    // system("cls");
    printf("--------------------------------------------------------\n");
    printf("DOUBLY_LINK-lINKED-LIST IMPLEMENTATION BY SAYANTAN\n");
    while (1)
    {
        printf("--------------------------------------------------------\n");
        printf("What do you want to do :- \n1) Insert data \n2) Delete data \n3) Modify list \n4) Reverse list \n5) Show data \n6) Search data \n7) Exit "); // sort (WIP)
        printf("\n--------------------------------------------------------\n");
        printf("Enter choice : ");
        scanf("%d", &c);
        printf("--------------------------------------------------------\n");
        switch (c)
        {
        case 1:
            printf("How many numbers u want to insert : ");
            scanf("%d", &n);
            printf("Where do u want them to insert (1=at the beginning; 2=at the end) : ");
            scanf("%d", &p);

            if (p == 1)
            {
                for (i = 0; i < n; i++)
                {
                    printf("Enter number at beginning: ");
                    scanf("%d", &x);
                    ins_beg(x);
                    display();
                }
            }
            else if (p == 2)
            {
                for (i = 0; i < n; i++)
                {
                    printf("Enter number at end : ");
                    scanf("%d", &x);
                    ins_end(x);
                    display();
                }
            }
            else
            {
                printf("invalid input\n");
            }

            break;

        case 2:
            printf("How do u want to delete element (1=delete element at specified position; 2=delete a specified element; 3=delete whole list) : ");
            scanf("%d", &del_c);
            if (del_c == 1)
            {
                printf("Which position do you want to delete : ");
                scanf("%d", &n);
                del_pos(n);
                display();
            }
            else if (del_c == 2)
            {
                printf("Which number do you want to delete : ");
                scanf("%d", &n);
                del_num(n);
                display();
            }
            else if (del_c == 3)
            {
                printf("Deleting the whole list...\n");
                delete_list();
            }
            else
            {
                printf("invalid input\n");
            }
            break;

        case 3:
            printf("At which position you want to insert/modify data : ");
            scanf("%d", &n);
            printf("Enter data You want to insert at pos %d : ", n);
            scanf("%d", &x);
            ins_pos(x, n);
            display();
            break;

        case 4:
            printf("List is reversed \n");
            reverse_list();
            display();
            break;

        case 5:
            display();
            break;

        case 6:
            printf("Enter a element you want to search : ");
            scanf("%d", &n);
            pos = search(n);
            if (pos == -1)
                printf("%d is not present in the list \n", n);
            else
                printf("%d is present at position %d \n", n, pos);

            break;
        case 7:
            printf("Exiting...");
            exit(0);
            break;

        case 8:
            // printf("sorting");
            // list_sort();
            // display;
            exit(0);
            break;

        default:
            printf("Exiting...");
            exit(0);
            break;
        }
        // printf("Size of the list : %d \n",lsize);
    }
    return 0;
}
