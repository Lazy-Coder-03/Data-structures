// CIRCULAR_LINK-lINKED-LIST IMPLEMENTATION BY SAYANTAN only using tail

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *tail = NULL;
int lsize = 0;

node *create_node(int x)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    lsize += 1;
    return newnode;
}

void ins_end(int x)
{
    node *newnode = create_node(x);
    if (tail == NULL)
    {
        // head = newnode;
        tail = newnode;
        tail->next = newnode;
        // tail->next = head;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        // tail->next = head;
        tail = newnode;
    }
    // tail->next = head;
}

void ins_beg(int x)
{
    node *newnode = create_node(x);
    if (tail == NULL)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void ins_pos(int x, int pos)
{
    node *newnode, *temp;
    int i = 1;
    if (pos < 0 || pos > lsize)
    {
        printf("Invalid Position\n");
        return;
    }
    else if (pos == 1)
        ins_beg(x);
    else if (pos == lsize)
        ins_end(x);
    else
    {
        newnode = create_node(x);
        temp = tail->next;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void del_beg()
{
    node *temp;
    if (tail != NULL)
        temp = tail->next;
    else
    {
        printf("List is Empty\n");
        return;
    }
    if (temp->next == temp)
    {
        tail = NULL;
        free(temp);
        lsize--;
    }
    else
    {
        tail->next = temp->next;
        free(temp);
        lsize--;
    }
}

void del_end()
{
    node *current, *prev;
    current = tail->next;
    if (tail == NULL)
        printf("List is Empty\n");
    else if (current->next == current)
    {

        tail = NULL;
        free(current);
        lsize--;
    }
    else
    {

        while (current->next != tail->next)
        {
            prev = current;
            current = current->next;
        }
        prev->next = tail->next;
        tail = prev;
        free(current);
        lsize--;
    }
}

void del_pos(int pos)
{
    node *current, *nextnode;
    int i = 1;

    if (tail == NULL)
        printf("List is Empty\n");
    else if (pos < 1 || pos > lsize)
        printf("Invalid Position\n");
    else if (pos == 1)
        del_beg();
    else if (pos == lsize)
        del_end();
    else
    {
        current = tail->next;
        while (i < pos - 1)
        {
            current = current->next;
            i++;
        }
        nextnode = current->next;
        current->next = nextnode->next;
        free(nextnode);
        lsize--;
    }
}

void delete_list()
{
    if (tail == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else
    {
        while (tail != NULL)
            del_beg();
        printf("Sucessfully deleted all elements in the list...\n");
    }
}

void reverse_list()
{
    node *current, *prev, *nextnode;
    current = tail->next;
    nextnode = current->next;
    if (tail == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    else if (current == current->next)
    {
        printf("One node present\n");
        return;
    }
    else
    {
        printf("Reversing list...\n");
        while (current != tail)
        {
            prev = current;
            current = nextnode;
            nextnode = current->next;
            current->next = prev;
        }
        nextnode->next = tail;
        tail = nextnode;
    }
}

void display()
{
    node *temp;
    if (tail == NULL)
    {
        printf("List Empty\n");
        return;
    }
    else
    {
        temp = tail->next;
        printf("List is : ");
        while (temp->next != tail->next)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
    printf("%d\n", temp->data);
}

int get_size()
{
    node *temp;
    int i = 1;
    if (tail == NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    else
    {
        temp = tail->next;
        while (temp->next != tail->next)
        {
            i++;
            temp = temp->next;
        }
    }
    return i;
}

int search(int key)
{
    int index;
    struct node *current;
    index = 1;
    current = tail->next;
    while (current->next != tail->next && current->data != key)
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

int Not_Main()
{
    // driver code
    int c = 1, x;
    while (c)
    {
        printf("Enter data : ");
        scanf("%d", &x);
        ins_beg(x);
        printf("Do u want to continue?");
        scanf("%d", &c);
    }
    display();
    ins_pos(50, 2);
    ins_pos(10, 1);
    // delete_list();
    ins_pos(100, lsize);
    display();
    del_pos(2);
    display();
    del_pos(5);
    display();
    del_end();
    display();
    del_beg();
    display();
    // delete_list();
    display();
    reverse_list();
    display();
    printf("Size of list = %d\n", get_size());
    printf("Size of list = %d\n", lsize);
    return 0;
}

int main()
{

    int n, i, x, c, p, del_c, pos;
    // char cont='y';
    // system("cls");
    printf("--------------------------------------------------------\n");
    printf("CIRCULAR_LINK-lINKED-LIST IMPLEMENTATION BY SAYANTAN\n");
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