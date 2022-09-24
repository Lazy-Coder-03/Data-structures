#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

node *create_node(int x)
{
    node *newnode=(node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void printList(node* node)
{
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

node * sortedInsert(node *headref,node *newnode)
{
    node *curr;
    if(headref == NULL || (headref)->data >=newnode->data)
    {
        newnode->next=headref;
        headref = newnode;
    }
    else 
    {
        curr = headref;
        while(curr->next!=NULL && curr->next->data<newnode->data)
            curr=curr->next;
        newnode->next=curr->next;
        curr->next=newnode;
    }
    return headref;
}

void free_list(node *head) {
    node *prev = head;
    node *cur = head;
    while(cur) {
        prev = cur;
        cur = prev->next;
        free(prev);
    }       
}

int main(){
    int num;
    node *head, *p ,*newnode;
    head = NULL;
    do {
        printf("Enter a number ");
        scanf("%d",&num);
        if(num) {
            newnode = create_node(num);
            sortedInsert(head, newnode);
        }
    } while(num);
    p = head;
    printf("\nThe numbers are:\n");
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    free_list(head);
    return 0;
}