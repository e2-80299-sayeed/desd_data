#ifndef __LIST_H
#define __LIST_H

typedef struct entry{
	int rollno;
	char name[20];
}entry_t;

typedef struct node{
	entry_t entry;
	struct node *next;
}node_t;

void init_list(node_t **head);
int is_empty(node_t *head);
node_t *create_node(int key, char *value);

void add_node(node_t **head, int key, char *value);
void display_list(node_t *head);
void free_list(node_t **head);

#endif









