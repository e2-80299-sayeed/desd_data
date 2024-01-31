// Doubly Circular Linked List
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *head = NULL;

void add_first(int data);
node *create_node(int data);
void display();
void add_last(int data);
void delete_first();
void delete_last();
void selection_sort();

int main()
{
    add_first(11);
    add_first(12);
    add_first(13);
    display();
    add_last(15);
    add_last(14);
    display();
   // delete_first();
    //display();
    //delete_last();
    selection_sort();
    display();
    return 0;
}

node *create_node(int data)
{
   node * new_node = (node *)malloc(sizeof(node));
   if(new_node == NULL)
        printf("Malloc Failed !");
    else
    {
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
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
        new_node->prev = new_node;
    }
    else
    {
        // forward connection between newnode and 1st node
        new_node->next = head;
        // backward conn between new node and last node
        new_node->prev = head->prev;
        // forward conn between last node and new node
        head->prev->next = new_node;
        // backward conn between 1st node and new node
        head->prev = new_node;
        // update the head pointer
        head = new_node;
    }
}

void display()
{
    if(head == NULL)
        printf("List is Empty !");
    else
    {
        node *trav = head;
        printf("Head");
        do{
            printf("->%d",trav->data);
            trav = trav->next;
        }while(trav!=head);
    }
    printf("\n");
}

void add_last(int data)
{
    node *new_node = create_node(data);
    if(head == NULL)
    {
        head = new_node;
        new_node->next = head;
        new_node->prev = head;
    }
    else
    {
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
    }
}

void delete_first()
{
    if(head == NULL)
        printf("List is Empty !");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *temp = head;
        // forward conn bet last node and 2nd node
        head->prev->next = head->next;
         // backward conn bet 2nd node and last node
        head->next->prev = head->prev;
        // update head pointer
        head = head->next;
        // free 1st node
        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head == NULL)
        printf("List is Empty !");
    else if(head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *temp = head->prev;
        temp->prev->next = head;
        head->prev = temp->prev;
        free(temp);
        temp = NULL;

    }
}

void selection_sort()
{
    node *i,*j;

    for(i=head; i->next!=head;i=i->next)
    {
        for(j=i->next; j != head;j=j->next)
        {
            if(i->data > j->data)
            {
                int temp =i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}