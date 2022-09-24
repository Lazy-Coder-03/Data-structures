// BINARY SEARCH TREE IMPREMENTATION

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
	int data;
	struct node *left, *right;
} node;

node* root = NULL;

node *create_node(int x)
{
    if(x!=-1)
    {
        node *newnode = (node*)malloc(sizeof(node));
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    return NULL;
}

node *insert_bst(node *root,int key)
{
    if(root==NULL)
        return create_node(key);
    if(key<root->data)
        root->left = insert_bst(root->left,key);
    else if(key>root->data)
        root->right = insert_bst(root->right,key);
    return root;
}

node *min_value_node(node *root)
{
    node *current = root;
    while(current && current->left)
        current=current->left;
    return current;
}

node *max_value_node(node *root)
{
    node *current = root;
    while(current && current->right)
        current=current->right;
    return current;
}

node *delete_bst(node *root,int key)
{
    node *temp;
    if (root==NULL) 
        return NULL;
    if (key<root->data)
        root->left=delete_bst(root->left,key);
    else if(key>root->data) 
        root->right=delete_bst(root->right,key);
    else 
    {
        if(root->left==NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = min_value_node(root->right);
        root->data = temp->data;
        root->right = delete_bst(root->right,temp->data);

    }
    return root;


} 

void inorder(struct node* root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    
}

int getHeight(struct node* node)
{
    if (node == NULL)
        return 0;
    else 
    {        
        int lheight = getHeight(node->left);
        int rheight = getHeight(node->right);
        return fmax(lheight,rheight) + 1;
    }
}

void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) 
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(struct node* root)
{
    int h = getHeight(root);
    int i;
    for (i = 1; i <= h; i++)
    {
        printCurrentLevel(root, i);
        printf("\n");
    }
}
 

int binary_search_bst(int key, struct node* root)
{
    if(root == NULL)
        return 0;
    if(root->data==key)
        return 1;
    else if(key<root->data)
        return binary_search_bst(key,root->left); 
    else if(key > root->data)   
        return binary_search_bst(key,root->right);
}

int main()
{

    int x;
    printf("Enter Data for Root (enter -1 to terminate): ");
    scanf("%d",&x);
    root = insert_bst(root,x);
    while(x!=-1)
    {
        printf("Enter Data (enter -1 to terminate): ");
        scanf("%d",&x);
        insert_bst(root,x);
    }
    inorder(root);
    printf("\n");
    if(binary_search_bst(10,root))
        printf("Found\n");
    else
        printf("Not found\n");
    //delete_bst(root,10);
    //inorder(root);
    //printLevelOrder(root);
}