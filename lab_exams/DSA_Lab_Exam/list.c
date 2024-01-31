#include"queue.h"

typedef struct person
{
    char name[SIZE];
    struct person *next;
}person;

queue Q;
person * create_node(char name[]);
void add_last(char name[]);
void delete_last(void);
void display1(void);
person *head = NULL;

int main(void)
{   int choice;
    do
    {
        printf("0.Exit\n1.add last\n2.delete last\n3.display list\n4.play the game");
        printf("\nEnter choice : ");
        scanf("%d",&choice);
        printf("\n");

        switch (choice)
        {
        case 0 : exit(0);
        case 1 : 
                char name[SIZE];
                printf("Enter name :");
                scanf("%s",name);
                printf("\n");
                add_last(name);
                break;
        case 2 : 
                delete_last();
                break;
        case 3 : display1();
                 break;
        
        case 4 :
                    //char* name1;
                    //strcpy((char*)name1,(char*)Q.name);
                    //push(&Q,name);

        default: printf("Enter valid choice !!\n");
                 break;
        }
    
    }while(choice != 0);

    return 0;
}

person * create_node(char name[])
{
    person *new_person = (person *)malloc(sizeof(person)); 

    if(new_person == NULL)
        printf("Malloc Failed !!");
    
    else
        {
            strcpy((char *)new_person->name,(char*) name);
            new_person->next = NULL;
        }
    return new_person;
}  

void add_last(char name[])
{
    person *new_person = create_node(name);

    if(head == NULL)
        {
            head = new_person;
            new_person->next = head; 
        }
    else
        {
            person *trav = head;

            while(trav->next != head);
            {
                trav = trav->next;
            }
            trav->next = new_person;
            new_person->next = head;   
        }
}

void delete_last(void)
{
    if(head == NULL)
        printf("List is empty !!");
    else
    {
            person *trav = head;
            while(trav->next->next != head)
            {
                trav = trav->next;
            }
            //push(&Q,trav->name);
            free(trav->next);                
            trav->next = head;
        } 

}

void display1(void)
{
    if(head == NULL)
        printf("List is Empty !!");
    else
    {
        person *trav = head;
        do
        {   
            printf("%4s",trav->name);
           trav = trav->next; 
        }while(trav != head);
    }
    printf("\n");

}