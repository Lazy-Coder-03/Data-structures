#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define bool int
typedef struct node 
{
    int data;
    struct node *next;
} node;

bool isPresent(struct node* head, int data)
{
    node* t = head;
    while (t != NULL) {
        if (t->data == data)
            return 1;
        t = t->next;
    }
    return 0;
}

node *create_node(int x)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void insert_beginning(node **head_ref,int x)
{
    node *newnode = create_node(x);
    newnode->next = *head_ref;
    *head_ref = newnode;
}




node* getUnion(struct node* head1, struct node* head2)
{
    node *resulthead = NULL;
    node *t1 = head1, *t2 = head2;
  
    // Insert all elements of
    // list1 to the result list
    while (t1 != NULL) {
        insert_beginning(&resulthead, t1->data);
        t1 = t1->next;
    }
  
    // Insert those elements of list2
    // which are not present in result list
    while (t2 != NULL) {
        if (!isPresent(resulthead, t2->data))
            insert_beginning(&resulthead, t2->data);
        t2 = t2->next;
    }
  
    return resulthead;
}

node* getIntersection(node* head1,node* head2)
{
    node* resulthead = NULL;
    node* t1 = head1;
  
    // Traverse list1 and search each element of it in
    // list2. If the element is present in list 2, then
    // insert the element to result
    while (t1 != NULL) {
        if (isPresent(head2, t1->data))
            insert_beginning(&resulthead, t1->data);
        t1 = t1->next;
    }
  
    return resulthead;
}

void printList(struct node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    /* Start with the empty list */
    node* head1 = NULL;
    node* head2 = NULL;
    node* intersecn = NULL;
    node* unin = NULL;
  
    /*create a linked lists 10->15->5->20 */
    insert_beginning(&head1, 2);
    insert_beginning(&head1, 4);
    insert_beginning(&head1, 6);
    insert_beginning(&head1, 8);
    insert_beginning(&head1, 10);
    insert_beginning(&head1, 12);
    insert_beginning(&head1, 14); 
    /*create a linked lists 8->4->2->10 */
    insert_beginning(&head2, 4);
    insert_beginning(&head2, 8);
    insert_beginning(&head2, 12);
    insert_beginning(&head2, 16);
    insert_beginning(&head2, 20);
  
    intersecn = getIntersection(head1, head2);
    unin = getUnion(head1, head2);
  
    printf("\nFirst list is \n");
    printList(head1);
  
    printf("\nSecond list is \n");
    printList(head2);
  
    printf("\nIntersection list is \n");
    printList(intersecn);
  
    printf("\nUnion list is \n");
    printList(unin);
  
    return 0;
}