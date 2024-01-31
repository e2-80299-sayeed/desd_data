//Singly Linear Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node* create_node(int data);
void add_first(int data);
void display();
void add_last(int data);
void add_at_position(int data,int pos);
int count_nodes();
void delete_first();
void delete_last();
void selection_sort();

int main()
{
    add_first(10);
    add_first(20);
    add_first(30);
   // display();
    add_last(40);
    add_last(50);
   // display();
    add_at_position(60,4);
    display();
    selection_sort();
    display();
  //  delete_first();
   // display();
   // delete_last();
    // display();
    return 0;
}

struct node* create_node(int data) // 40
{
   struct node *ptr = (struct node *)malloc(sizeof(struct node));

   if(ptr == NULL)
    printf("Malloc Failed !\n");
    else
    {
        ptr->data = data; // 40
        ptr->next = NULL; // NULL
    }
    return ptr;
}

void add_first(int data) // 10
{
    // create the node
    struct node* ptr = create_node(data); //10
    // attach the node
    // a) if the list is empty
    if(head == NULL)
    {
        head = ptr;
    }
    else // if the list contains multiple nodes
    {
        ptr->next = head;  // create a connection between new node and 1st node
        head = ptr; // create a connection between head and new node
    }
}

void display()
{
    if(head == NULL) // list is empty
    {
        printf("List is Empty !\n");
    }
    else
    {
        struct node *trav = head;
        printf("Head");
        while(trav!= NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
    }
    printf("\n");
}

void add_last(int data) // 40
{
    struct node *ptr = create_node(data); // 40

    if(head == NULL)
        head = ptr;
    else
    {
        struct node *trav = head;
        while(trav->next != NULL) // to stop at the last node
        {
            trav = trav->next;
        }
        trav->next = ptr;
    }
}

void add_at_position(int data,int pos)
{
    // if list is empty
    if(head == NULL) // 5
    {
        if(pos == 1)
            add_first(data);
        else // 5
            printf("List is Empty !");
    }
    else if(pos == 1)
    {
        add_first(data);
    }
    else if(pos == count_nodes()+1)
    {
        add_last(data);
    }
    else if(pos < 1 || pos > count_nodes()+1)
    {
        printf("Invalid Position !\n");
    }
    else
    {
        struct node *ptr = create_node(data);
        struct node *trav = head;
        for(int i=1;i <pos-1;i++) // 1 < 2 --> 2<2
        {
            trav = trav->next;
        }
        ptr->next = trav->next;
        trav->next = ptr;
    }
}

int count_nodes()
{
    int count = 0;
    if(head == NULL)
        printf("List Empty !");
    else
    {
        struct node *trav = head;
        

        while(trav!= NULL)
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
    else if(head->next == NULL) // list contains only 1 node
    {
        free(head);
        head = NULL;
    }
    else // if list contains multiple nodes
    {
        struct node *temp = head;
        head = head->next; // head = temp->next;
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
    }
    else 
    {
        struct node *trav = head;

        while(trav->next->next != NULL) // to stop at the 2nd last node
        {
            trav = trav->next;
        }
        free(trav->next);
        trav->next = NULL;
    }
}

void selection_sort()
{
   struct node *i, *j;
   for(i=head; i->next !=NULL; i=i->next)
   {
    for(j=i->next; j!=NULL; j=j->next)
    {
        if(i->data > j->data)
        {
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }
   }
}