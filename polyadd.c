#include<stdio.h>
#include<stdlib.h>
typedef struct polynode {
    float coef;
    int expo;
    struct polynode *next;
}pnode;

pnode *create_node(int co,int ex)
{
    pnode *newnode = (pnode *)malloc(sizeof(pnode));
    newnode->coef = co;
    newnode->expo = ex;
    newnode->next = NULL;
}

pnode *insert_poly(pnode *head,float co, int ex)
{
    pnode *temp = NULL;
    pnode *newP = create_node(co,ex);

    if((head == NULL) || ex>head->expo)
    {
        newP->next = head;
        head = newP;
    }
    else
    {
        temp = head;
        while(temp->next != NULL && temp->next->expo >= ex)
            temp = temp->next;
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}

pnode *create_poly(pnode *head)
{
    int n,i;
    float coe;
    int exp;
    printf("Enter the no of terms : ");
    scanf(" %d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Coefficient of term %d : ",i+1);
        scanf("%f",&coe);
        printf("Enter Exponent of term %d : ",i+1);
        scanf("%d",&exp);
        head = insert_poly(head, coe, exp);
    }
    return head;
}

void free_list(pnode *head) {
    pnode *prev = head;
    pnode *cur = head;
    while(cur) {
        prev = cur;
        cur = prev->next;
        free(prev);
    }       
}

void print_poly(pnode *head)
{
    pnode *temp=NULL;
    if(head == NULL)
    {
        printf("No Polynomial\n");
        return;
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            if(temp->coef>=0)
                printf("+ (%.1f*x^%d) ",temp->coef,temp->expo);
            else
                printf("(%.1f*x^%d) ",temp->coef,temp->expo);

            temp = temp->next;
        }
        printf("\n");
    }
}

void poly_add(pnode *head1,pnode *head2)
{
    pnode *ptr1=head1;
    pnode *ptr2=head2;
    pnode *head3=NULL;
    float coefsum;

    while(ptr1!= NULL && ptr2 != NULL)
    {
        coefsum = ptr1->coef+ptr2->coef;
        if(ptr1->expo == ptr2->expo)
        {
            head3 = insert_poly(head3,coefsum,ptr1->expo);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            head3 = insert_poly(head3,ptr1->coef,ptr1->expo);
            ptr1=ptr1->next;
        }
        else if(ptr1->expo < ptr2->expo)
        {
            head3 = insert_poly(head3,ptr2->coef,ptr2->expo);
            ptr2=ptr2->next;
        }
    }
    while(ptr1 != NULL)
    {
        head3 = insert_poly(head3,ptr1->coef,ptr1->expo);
        ptr1=ptr1->next;
    }
    while(ptr2 != NULL)
    {
        head3 = insert_poly(head3,ptr2->coef,ptr2->expo);
        ptr2=ptr2->next;
    }
    printf("Added Polynomial is : ");
    print_poly(head3);
    free_list(head1);
    free_list(head2);
    free_list(head3);
}


int main(int argc, char **argv)
{
    pnode *head1=NULL;
    pnode *head2=NULL;
    printf("Enter the First Polynomial\n");
    head1=create_poly(head1);
    printf("1st Polynomial\n");
    print_poly(head1);
    printf("\nEnter the Second Polynomial\n");
    head2=create_poly(head2);
    printf("2nd Polynomial\n");
    print_poly(head2);
    poly_add(head1,head2);

    return 0;

}
