#include<stdio.h>
#include<stdlib.h>
struct polynode {
    int coef;
    int expo;
    struct polynode *next;
};
typedef struct polynode pn;
pn *insert(pn *head, int co , int ex);
pn *create(pn *head);
void print(pn *head);
void polyadd(pn *head1, pn *head2);
pn *insert(pn *head, int co , int ex) {
    pn *temp;
    pn *newP = (pn *)malloc(sizeof(pn));
    newP->coef = co;
    newP->expo = ex;
    newP->next = NULL;
    if(head == NULL || ex > head->expo) {
        newP->next = head;
        head = newP;
    }
    else {
        temp = head;
        while(temp->next != NULL && temp->next->expo >= ex) {
            temp = temp->next;
        }
        newP->next = temp->next;
        temp->next = newP;
    }
    return head;
}
pn *create(pn *head) {
    int n, i, co, ex;
    printf("\nEnter the numbers of term: ");
    scanf("%d" ,&n);
    for(i = 0; i < n; i++) {
        printf("\nEnter the coefficient of term %d: " ,i+1);
        scanf("%d" ,&co);
        printf("\nEnter the exponent of term %d: " ,i+1);
        scanf("%d" ,&ex);

        head = insert(head, co ,ex);
    }
    return head;
}
void print(pn *head) {
    if (head == NULL) {
        printf("\nNo polynomial found.");
    }
    else {
        pn *temp = head;
        while(temp != NULL) {
            printf("%dx^%d" ,temp->coef ,temp->expo);
            if(temp->next != NULL && temp->next->coef > 0) {
                printf(" + ");
            }else {
                printf(" ");
            }
            temp = temp->next;
        }
    }
}
void polyadd(pn *head1, pn *head2) {
    pn *ptr1 = head1;
    pn *ptr2 = head2;
    pn *head3 = NULL;
    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1->expo == ptr2->expo) {
            head3= insert(head3, ptr1->coef+ptr2->coef, ptr1->expo);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        } 
        else if(ptr1->expo > ptr2->expo){
            head3 = insert(head3, ptr1->coef, ptr1->expo);
            ptr1 = ptr1->next;
        }
        else {
            head3 = insert(head3 ,ptr2->coef, ptr2->expo);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != NULL) {
        head3 = insert(head3, ptr1->coef, ptr1->expo);
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL) {
        head3 = insert(head3 ,ptr2->coef, ptr2->expo);
        ptr2 = ptr2->next;
    }
    printf("\nThe added polynomial is: ");
    print(head3); 

}
int main() {
    pn *head1 = NULL;
    pn *head2 = NULL;
    printf("Enter the 1st polynomial: ");
    head1 = create(head1);
    printf("\nEnter the 2nd polynomial: ");
    head2 = create(head2);

    polyadd(head1 , head2);
    return 0;
}