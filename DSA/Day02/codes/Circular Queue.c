// Circular Queue
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct queue
{
    int arr[SIZE];
    int rear;
    int front;
}queue;

void init_queue(queue *pq);
int get_front(queue *pq);
void enqueue(queue *pq,int data);
void dequeue(queue *pq);
int queue_empty(queue *pq);
int queue_full(queue *pq);

int main()
{
        int choice,data;
    queue Q;
    init_queue(&Q);
do{
    printf("0.Exit\n1.Enqueue\n2.Dequeue\n :\n");
    printf("Enter the choice : \n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0 : exit(0);
        case 1: // Enqueue
                if(queue_full(&Q))
                    printf("Queue is Full !\n");
                else
                {
                    printf("Enter the element to insert :");
                    scanf("%d",&data);
                    enqueue(&Q,data);
                    printf("Element inserted !\n");
                }
                break;
        case 2: // dequeue
                if(queue_empty(&Q))
                    printf("Q is Empty !\n ");
                else
                {
                    int ele;
                    ele = get_front(&Q);
                    dequeue(&Q);
                    printf("Element Deleted = %d\n",ele);
                }
                break;
        default :
                printf("Enter the valid choice !\n");
    }
}while(choice != 0);

    return 0;
}


void init_queue(queue *pq)
{
    pq->rear = -1;
    pq->front = -1;
}

void enqueue(queue *pq,int data)
{
    // increment the rear
    pq->rear = (pq->rear+1) % SIZE;
    // insert data at rear position
    pq->arr[pq->rear] = data;
    // if front is at -1, get front to 0
    if(pq->front == -1)
        pq->front = 0;
}

void dequeue(queue *pq)
{
    if(pq->front == pq->rear)
    {
        pq->front = pq->rear = -1;
    }
    else
    {
        pq->arr[pq->front] = 0;
        pq->front = (pq->front + 1)% SIZE;
    }
}

int queue_empty(queue *pq)
{
    return (pq->rear == -1);
}

int queue_full(queue *pq)
{
    return (pq->front == (pq->rear+1) % SIZE);
}

int get_front(queue *pq)
{
    return pq->arr[pq->front];
}

/*

// Circular Queue

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct queue
{
    int arr[SIZE];
    int front; 
    int rear;
}queue;
 
void init_queue(queue *pq);
void enqueue(queue *pq,int val);
void dequeue(queue *pq);
int is_queue_full(queue *pq);
int is_queue_empty(queue *pq);
int get_front(queue *pq);
void display(queue *pq);
int main()
{
    int choice,value;
    queue Q;
    init_queue(&Q);
do
{
    printf("\nEnter the choice \n");
    printf("0. Exit\n1.Enqueue\n2.Dequeue\n3.Display\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0:
            exit(0);
        case 1:
            if(is_queue_full(&Q))
                printf("Queue is full !");
            else
            {
                printf("enter the value !");
                scanf("%d",&value);
                enqueue(&Q,value);
                printf("%d is pushed into queue !",value);
            }
            break;
        case 2:
            if(is_queue_empty(&Q))
                printf("Queue is empty !");
            else
            {
                int num = get_front(&Q);
                dequeue(&Q);
                printf("Value deleted = %d\n",num);

            }
            break;
        case 3:
            if(is_queue_empty(&Q))
                printf("Queue is empty !");
            else
                display(&Q);
            break;
        default :
            printf("enter valid choice !");
    }
}while(choice != 0);

    return 0;
}

void init_queue(queue *pq)
{
    pq->front = -1;
    pq->rear = -1;
}

void enqueue(queue *pq,int val)
{
    pq->rear = (pq->rear+1)%SIZE; // instead of pq->rear++
    pq->arr[pq->rear] = val;
    if(pq->front == -1)
        pq->front = 0;
}

void dequeue(queue *pq)
{
    if(pq->front == pq->rear) // deleteing last element
        pq->front = pq->rear = -1;
    else
        pq->front = (pq->front+1) % SIZE; // instead of pq->front++
}

int is_queue_full(queue *pq)
{
    if(pq->front == (pq->rear +1) % SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_queue_empty(queue *pq)
{
    if(pq->rear == -1 )
        return 1;
        else
        return 0;
}

int get_front(queue *pq)
{
    return pq->arr[pq->front];
}

void display(queue *pq)
{
 if (pq->rear >= pq->front) 
 {
        for (int i = pq->front; i <= pq->rear; i++)
         {
            printf("%d ", pq->arr[i]);
        }
    } 
else {
        for (int i = pq->front; i < SIZE; i++) {
            printf("%d ", pq->arr[i]);
        }
        for (int i = 0; i <= pq->rear; i++) {
            printf("%d ", pq->arr[i]);
        }
    }
}





*/