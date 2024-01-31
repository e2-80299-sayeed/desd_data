#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next; 
}node;
node* create_node(int data);
void add_first(int data);
void display(void);
node *head = NULL;

int main(void)
{
	add_first(10);
	add_first(20);
	add_first(30);
	add_first(40);

	display();
	return 0;
}

node* create_node(int data)
{
	node *new_node = (node *)malloc(sizeof(node));

	if(new_node == NULL)
		printf("Malloc failed");
	else 
	{
		new_node->data = data;
		new_node->next = NULL; 	
	}
	return new_node;
}
void add_first(int data)
{
	node *new_node = create_node(data);

	if(head == NULL)
		{
			head = new_node;
			new_node->next = head;
		}
	else 
		{
			node *trav = head;
		while(trav->next != head)
		{
			trav = trav->next;	
		}

			new_node->next = head;
			head = new_node;
			trav->next = head;
		}
}

void display(void)
{
	if(head == NULL)
		printf("List is Empty !!");
	else
		{
		node *trav = head;
		printf("Head");
		do 
			{
				printf("->%d",trav->data);
				trav = trav->next;
			}while(trav != head);
		}	
		printf("\n");
}