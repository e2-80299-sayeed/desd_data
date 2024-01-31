#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"list.h"

void init_list(node_t **head)
{
	*head = NULL;
}
int is_empty(node_t *head)
{
	return head == NULL;
}
node_t *create_node(int key, char *value)
{
	node_t *newnode = (node_t *)malloc(sizeof(node_t));

	newnode->entry.rollno = key;
	strcpy(newnode->entry.name, value);
	newnode->next = NULL;

	return newnode;
} 

void add_node(node_t **head, int key, char *value)
{
	node_t *newnode = create_node(key, value);
	if(is_empty(*head))
		*head = newnode;
	else
	{
		newnode->next = *head;
		*head = newnode;
	}
}
void display_list(node_t *head)
{
	if(!is_empty(head))
	{
		node_t *trav = head;
		while(trav != NULL)
		{
			printf("[%d][%s] -", trav->entry.rollno, trav->entry.name);
			trav = trav->next;
		}
	}
}
void free_list(node_t **head)
{
	if(!is_empty(*head))
	{
		node_t *trav = *head;
		while(trav != NULL)
		{
			node_t *temp = trav;
			trav = trav->next;
			free(temp);
		}
		*head = NULL;
	}
}











