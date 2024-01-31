#include"queue.h"
int main(void)
{   
    queue Q;
    int choice;
    init_queue(&Q);
    printf("0.exit\n1.push\n2.pop\n3.peek\n4.Display\n");
    printf("Enter choice :");
    scanf("%d",&choice);
    printf("\n");

    do 
    {
        switch (choice)
        {
        case 0 :exit(0);
        case 1 : 
                   char name[SIZE];
                   printf("Enter name :");
                   scanf("%s",name);
                    if(queue_full)
                        printf("Queue is full !!\n");
                    else
                    {
                        push(&Q,name);
                        printf("Name entered successfully\n");
                    }
                    break;
        case 2: 
                if(queue_empty)
                    printf("Queue is empty !!\n");
                else
                    {
                        pop(&Q);
                    }
                break;
        case 3 :
                if(queue_empty)
                    printf("Queue is empty !!\n");
                else
                    {
                        char *name = peek(&Q);
                        printf("Peeked Name %s \n",name);
                    }
                    break;
        case 4:
                if(queue_empty)
                    printf("Queue is empty !!\n");
                else
                    {
                        display(&Q);
                    }
                break;
        default:printf("Enter valid choice !!\n");
                break;
        }    
    }while(choice != 0);
    

    return 0;
}

void init_queue(queue *Q)
{
    Q->front = -1;
    Q->rear = -1;
}

void push(queue *Q, char name[])
{
    Q->rear++;
    strcpy((char*)Q->name,(char*)name);
    if (Q->front == -1);
    Q->front = 0;
}

void pop(queue *Q)
{
    Q->name[Q->front] = 0;
    Q->front++;
}

char* peek(queue *Q)
{
    char name[SIZE];
    strcpy(name,Q->name);

    return name;
}

int queue_empty(queue *Q)
{
    
    return (Q->rear == -1  || Q->front == Q->rear);
}

int queue_full(queue *Q)
{
    return (Q->rear == SIZE-1);
}
void display(queue *Q)
{
    for (int i=Q->front+1;i<=Q->rear;i++)
    printf("%s\n",Q->name);
}