// BINARY TREE IMPLEMENTATION BY SAYANTAN RECURRSIVE APPROACH

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
	int data;
	struct node *left, *right;
} node;

node *root;

node *create_node()
{
    node *newnode = (node *)malloc(sizeof(node));
    int x;
    printf("Enter data(-1 for no node) : ");
    scanf("%d", &x);
    if (x == -1)
    {
        return NULL;
    }
    else
    {
        newnode->data = x;
        printf("Enter Left Child of %d :\n",x);
        newnode->left=create_node();
        printf("Enter Right Child of %d :\n",x);
        newnode->right=create_node();
        return newnode;
    }
}

void preorder_display(node *rut)
{
    if(rut == NULL)
    {
        return;
    }
    else
    {
        printf("%d ",rut->data);
        preorder_display(rut->left);
        preorder_display(rut->right);
    }
    //printf("\n");
}

void inorder_display(node *rut)
{
    if(rut == NULL)
    {
        return;
    }
    else
    {

        inorder_display(rut->left);
        printf("%d ",rut->data);
        inorder_display(rut->right);
    }
    //printf("\n");
}

void postorder_display(node *rut)
{
    if(rut == NULL)
    {
        return;
    }
    else
    {

        postorder_display(rut->left);
        postorder_display(rut->right);
        printf("%d ",rut->data);
    }
    //printf("\n");
}

int get_height(node *root)
{
    if(root != NULL)
    {
        int lheight = get_height(root->left);
        int rheight = get_height(root->right);
        int ans = fmax(lheight,rheight)+1;
        return ans;
    }
    return -1;
}

/*int isEmpty(struct sNode *top)
{
   return (top == NULL)? 1 : 0;
} */

/*void inOrder(struct tNode *root)
{
  
  struct tNode *current = root;
  struct sNode *s = NULL;  
  int done = 0;
 
  while (!done)
  {
    
    if(current !=  NULL)
    {
      
      push(&s, current);                                              
      current = current->left; 
    }
        

    else                                                             
    {
      if (!isEmpty(s))
      {
        current = pop(&s);
        printf("%d ", current->data);
 

        current = current->right;
      }
      else
        done = 1;
    }
  } 
}*/



int main()
{
    root = create_node();
    printf("Preorder  : ");
    preorder_display(root);
    printf("\n");
    printf("Ineorder  : ");
    inorder_display(root);
    printf("\n");
    printf("Postorder : ");
    postorder_display(root);
    printf("\n");
    printf("Height = %d",get_height(root));
}