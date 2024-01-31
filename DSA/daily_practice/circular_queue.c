#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct circular_queue
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
void display(queue *pq);

int main()
{
    int choice, data;
    queue Q;
    init_queue(&Q);
do{
    printf("0.Exit\n1.Enqueue\n2.Dequeue\n3.Display\n ");
    printf("Enter the choice :\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0 : exit(0);

        case 1 : 
                if(queue_full(&Q))
                    printf("Queue is full!\n");
                else
                {
                    printf("Enter the element to insert :");
                    scanf("%d",&data);
                    enqueue(&Q,data);
                    printf("Element inserted...\n");            
                }
                break;
        case 2 :
                if(queue_empty(&Q))
                    printf("Queue is Empty!\n");
                else
                    {
                        int ele;
                        ele = get_front(&Q);
                        dequeue(&Q);
                        printf("Element Deleted = %d\n",ele);
                    } 
                    break;
        case 3 :
                    printf("Queue : ");
                    display(&Q);
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

void enqueue(queue *pq, int data)
{
    pq->rear = (pq->rear + 1) % SIZE;
    pq->arr[pq->rear] = data;

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
        pq->front = (pq->front + 1) % SIZE;
    }
}

int queue_empty(queue *pq)
{
    return (pq->rear == -1);
}

int queue_full(queue *pq)
{
    return (pq->front == (pq->rear + 1) % SIZE);
}

int get_front(queue *pq)
{
    return pq->arr[pq->front];
}

void display(queue *pq)
{
    int i = 0;
    if(queue_empty(pq))
        printf("Queue is Empty!\n");
        
    else if(pq->rear >= pq->front)
            {
                for( i = pq->front ; i <= pq->rear ; i++)
                 printf("%4d",pq->arr[i]);
            }
    else
        {
            for(i = pq->front ; i < SIZE; i++)
                printf("%4d", pq->arr[i]);
            
            for( i = 0; i <= pq->rear; i++)
                printf("%4d", pq->arr[i]);
        }
    printf("\n");
}