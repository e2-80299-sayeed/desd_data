#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node *next;  
}node;

node *head = NULL;
node *create_node(int data);
void add_first(int data);
void display();
void add_last(int data);
void add_specific_pos(int data, int pos);
int count_nodes();
void delete_first();
void delete_last();
void delete_specific_pos(int pos);
void rev_print_list(node * trav);

int main()
{
    add_first(10);
    add_first(20);
    add_first(30);
    display();
    add_last(40);
    add_last(50);
    display();
    add_specific_pos(60,1);
    add_specific_pos(65,4);
    add_specific_pos(70,8);
    display();
    add_specific_pos(80,10);
    add_specific_pos(100,-2);
    delete_first();
    delete_last();
    delete_specific_pos(3);
    delete_specific_pos(2);
    display();
    
    rev_print_list(head);
    printf("<-Head");
    printf("\n");
    return 0;
}

node *create_node(int data)
{
    node *new_node = (node *)malloc(sizeof(node));

    if(new_node == NULL)
        printf("Malloc Failed !\n");
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
        head = new_node;
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void display()
{
    if(head == NULL)
        printf("List to Empty");
    else
    {
        node *trav = head;
        printf("head");
        while (trav != NULL)
        {
            printf("->%d",trav->data);
            trav = trav->next;
        }
    }
    printf("\n");
}

void add_last(int data)
{
    node *new_node = create_node(data);

    if(head ==  NULL)
        head = new_node;
    else
    {
        node *trav = head;
        while(trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = new_node;
    }
}

void add_specific_pos(int data, int pos)
{
    if(head == NULL)
    {
        if(pos == 1)
            add_first(data);
        else
            printf("List is Empty !");
    }
    else if(pos  == 1)
    {
        add_first(data);
    }
    else if(pos == count_nodes()+1)
    {
        add_last(data);
    }
    else if(pos < 1 || pos > count_nodes()+1)
    {
        printf("Invalid Position to add !\n");
    }
    else
    {
        node *new_node = create_node(data);

        node *trav = head;
        for(int i = 1; i < pos-1; i++)
            {
                trav = trav->next;
            }
            new_node->next = trav->next;
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

        while (trav != NULL)
        {
           count++;
            trav  = trav->next;
        }
    }
    return count;
}

void delete_first()
{
    if(head == NULL)
        printf("List is Empty");
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *temp = head;
        head = head->next;

        free(temp);
        temp = NULL;
    }
    
}

void delete_last()
{
    if(head == NULL)
        printf("List is Empty");
    else if(head->next == NULL) 
    {
        free(head);
        head = NULL;
    }
    else
    {
        node *trav = head;
       while(trav->next->next != NULL)
        {
            trav = trav->next;
        }
            free(trav->next);
            trav->next = NULL;
    }
}

void delete_specific_pos(int pos)
{
    if(head == NULL)
        printf("List is Empty");

    else if(pos == 1)
        delete_first();
    
    else if(pos == count_nodes())
        delete_last();
    
    else if(pos < 1 || pos > count_nodes())
        printf("Invalid Position to delete");
    
    else
        {
            node *trav = head;
            for (int i =1; i < pos-1; i++)
                {
                    trav = trav->next;
                }
            node *temp = trav->next;
            trav->next = trav->next->next;

            free(temp);
            temp = NULL;
        }
}

void rev_print_list(node * trav)
{
    if(trav == NULL)
        return;
    rev_print_list(trav->next);
    printf("<-%-4d",trav->data);
}