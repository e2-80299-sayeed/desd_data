// singly circular linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head = NULL;

node* create_node(int data);
void add_first(int data);
void display();
void add_last(int data);
void delete_first();
void delete_last();

int main()
{
    add_first(2);
    add_first(1);
    add_first(5);
    //display();
    add_last(8);
    add_last(4);
    add_last(9);
    add_last(6);
    display();
    //delete_first();
   // display();
    //delete_last();
   // display();

    return 0;
}

node* create_node(int data)
{
   node *new_node = (node*)malloc(sizeof(node));
   if(new_node == NULL)
    printf("Malloc Failed !");
    else
    {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

void add_first(int data)
{
    // create a node
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
        trav->next = head; // trav->next = new_node
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
        }while(trav != head);
        printf("\n");
    }
}

void add_last(int data)
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
        trav->next = new_node;
        new_node->next = head;
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
        // traverse till last node
        node *trav = head;
        while(trav->next != head)
        {
            trav = trav->next;
        }
        // store the address of 1st node
        node *temp = head;
        // update the head pointer
        head = head->next; 
        //update the pointer of last node
        trav->next = head;
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
        node *trav = head;
        while(trav->next->next != head)
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = head;
    }
}



