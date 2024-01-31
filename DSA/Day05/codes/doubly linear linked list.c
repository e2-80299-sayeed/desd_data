// doubly linear linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;

node *head = NULL;
node *tail = NULL;

void add_first(int data);
void backward_display();
void forward_display();
node *create_node(int data);
void add_last(int data);
int count_nodes();
void add_at_pos(int data,int pos);
void delete_first();
void delete_last();
void delete_at_pos(int pos);

int main()
{
    add_first(11);
    add_first(22);
    add_first(33);
    add_last(44);
    add_last(55);
    add_last(66);
   // forward_display();
    //backward_display();
    add_at_pos(77,5);
    forward_display();
   // delete_first();
   // forward_display();
    //delete_last();
    //forward_display();
    delete_at_pos(4);
    forward_display();
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
        tail = new_node;
    }
    else
    {
        // create forward connection between newmnode and 1st node
        new_node->next = head;
        // create backward connection between 1st node and newnode
        head->prev = new_node;
        // update the head pointer
        head = new_node;
    }

}

void forward_display()
{
    if(head == NULL)
        printf("List is Empty !");
    else
    {
        node *trav = head;
        printf("Head");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
        printf("\n");
    }
}

void backward_display()
{
    if(head == NULL)
        printf("Lis is Empty !");
    else
    {
        node *trav = tail;
        printf("Tail");
        while(trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->prev;
        }
        printf("\n");
    }
}

void add_last(int data)
{
    node *new_node = create_node(data);

    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        // create forward connection between last node and new node
        tail->next = new_node;
        // create backward connection between newnode and last node
        new_node->prev = tail;
        // update the tail pointer
        tail = new_node;
    }
}

void add_at_pos(int data,int pos)
{
    if(head == NULL)
    {
        if(pos == 1)
            add_first(data);
        else
            printf("List is Empty !");
    }
    else if(pos == 1)
        add_first(data);
    else if(pos == count_nodes()+1)
        add_last(data);
    else if(pos < 1 || pos > count_nodes()+1)
        printf("Invalid Position !");
    else
    {
        node *new_node = create_node(data);
        node *trav = head;
        for(int i = 1; i <pos-1; i++)
        {
            trav = trav->next;
        }
        // forward connection between newnode and pos node
        new_node->next = trav->next;
        // backward connection between newnode and pos -1 node
        new_node->prev = trav;
        // backward connextion between pos node and newnode
        trav->next->prev = new_node;
        // forward connection between pos-1 node and new node
        trav->next = new_node;
    }
}

int count_nodes()
{
    int count = 0;
    if(head == NULL)
        printf("List is Empty !");
    else
    {
        
        node *trav = head;
        while(trav != NULL)
        {
            count++;
            trav = trav->next;
        }
    }
    return count;
}

void delete_first()
{
    if(head == NULL)
        printf("List is Empty !");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        // store the address of 1st node in temp pointer
        node *temp = head; 
        // update the head pointer to point to 2nd node
        head = head->next;
        //update the prev pointer of 2nd node to NULL
        head->prev = NULL;
        // free 1st node
        free(temp);
        temp = NULL;
    }
}

void delete_last()
{
    if(head == NULL)
        printf("List is Empty !");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else
    {
        node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
        temp = NULL;
    }
}

void delete_at_pos(int pos)
{
    if(head == NULL)
        printf("List is Empty !");
    else if(pos == 1)
        delete_first();
    else if(pos == count_nodes())
        delete_last();
    else if(pos <1 || pos > count_nodes())
        printf("Invalid Position !");
    else
    {
        node *trav = head;
        for(int i = 1;i<pos-1;i++)
        {
            trav = trav->next;
        }
        node *temp = trav->next;
        trav->next = temp->next; // forward connection
        temp->next->prev = trav; // backward connection
        free(temp);
        temp = NULL;
    }
    
}