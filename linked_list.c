// SINGLE_LINK-lINKED-LIST IMPLEMENTATION BY SAYANTAN

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

node *head = NULL;
int lsize = 0;

node *new_node()
{
	node *temp = (node *)malloc(sizeof(node));
	return temp;
}

void insert_beginning(int x)
{
	lsize += 1;
	node *temp = new_node(); //(node *) malloc (sizeof (node));
	temp->data = x;
	temp->next = head;
	head = temp;
}

void insert_end(int n)
{
	node *temp = new_node(); //(struct node *)malloc(sizeof(struct node));
	node *p = head;
	lsize += 1;
	temp->data = n;
	temp->next = NULL;

	if (head == NULL)
	{
		temp->next = NULL;
		head = temp;
	}
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = temp;
		temp->next = NULL;
	}
}

void insert_pos(int x, int n)
{
	int i;
	lsize += 1;
	node *temp = new_node(); //(node *) malloc (sizeof (node));
	temp->data = x;
	temp->next = NULL;

	if (n == 1)
	{
		temp->next = head;
		head = temp;
		return;
	}
	if (n <= 0 || n > lsize)
	{
		printf("Invalid position!! still inserting number at the end \n");
		n = lsize;
	}
	node *prev = head;
	for (i = 0; i < n - 2; i++)
	{
		prev = prev->next;
	}
	temp->next = prev->next;
	prev->next = temp;
}

int search(int key)
{
	int index;
	struct node *current;
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

void delete_nth(int n)
{
	int i;
	if (n <= 0 || n > lsize)
	{
		printf("Invalid position!! \n");
		// n=lsize;
		return;
	}

	if (head == NULL)
	{
		printf("List Empty !\n");
		return;
	}
	lsize -= 1;
	node *prev = head;
	if (n == 1)
	{
		head = prev->next;
		printf("%d is deleted\n", prev->data);
		free(prev);
		return;
	}
	for (i = 0; i < n - 2; i++)
	{
		prev = prev->next; // n-1th node
	}
	node *current = prev->next; // nth node
	prev->next = current->next;
	printf("%d is deleted\n", current->data);
	free(current);
}

void delete_num(int key)
{
	int pos;
	pos = search(key);

	if (pos == -1)
		printf("Element not present\n");
	else
	{
		// lsize=lsize-1;
		delete_nth(pos);
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

void reverse_list()
{
	node *current = head;
	node *prev = NULL;
	node *nextadd;
	if (head == NULL)
	{
		printf("Empty list");
		return;
	}
	while (current != NULL)
	{
		nextadd = current->next;
		current->next = prev;
		prev = current;
		current = nextadd;
	}

	head = prev;
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
	}
	else
		printf("List Empty \n");
}

void swap(int a, int b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

void list_sort()
{
	node *temp = head;
	node *nextadd;
	int a, b;
	while (nextadd != NULL)
	{
		nextadd = temp->next;
		// a = temp->data;
		// b = nextadd->data;

		if (temp->data > nextadd->data)
			swap(temp->data, nextadd->data);

		temp = temp->next;
	}
}

int main()
{

	int n, i, x, c, p, del_c, pos;
	// char cont='y';
	// system("cls");
    printf("\n--------------------------------------------------------\n");
	printf("SINGLE_LINK-lINKED-LIST IMPLEMENTATION BY SAYANTAN\n");
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
					insert_beginning(x);
					display();
				}
			}
			else if (p == 2)
			{
				for (i = 0; i < n; i++)
				{
					printf("Enter number at end : ");
					scanf("%d", &x);
					insert_end(x);
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
				delete_nth(n);
				display();
			}
			else if (del_c == 2)
			{
				printf("Which number do you want to delete : ");
				scanf("%d", &n);
				delete_num(n);
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
			insert_pos(x, n);
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
			printf("sorting");
			list_sort();
			display;
			// exit(0);
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
