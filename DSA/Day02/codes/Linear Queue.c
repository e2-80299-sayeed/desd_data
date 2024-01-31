// Linear Queue
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
void enqueue(queue *pq, int data);
void dequeue(queue *pq);
int queue_full(queue *pq);
int queue_empty(queue *pq);
int get_front(queue *pq);

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

void enqueue(queue *pq, int data)
{
    // increment the rear
    pq->rear++;
    // insert the data at the rear position
    pq->arr[pq->rear] = data;
    // if front is at -1 bring front to 0
    if(pq->front == -1)
        pq->front = 0;

}

void dequeue(queue *pq)
{
    // optional : replace 0 to arr[front]
    pq->arr[pq->front] = 0;
    // increment front
    pq->front++;
}

int queue_full(queue *pq)
{
    return(pq->rear == SIZE-1);
    /*
        if(pq->rear == SIZE-1)
            return 1;
        else
            return 0;
    */
}

int queue_empty(queue *pq)
{
    return (pq->rear == -1 || pq->front > pq->rear);
    /*
        if(pq->rear == -1 || pq->front > pq->rear)
            return 1;
        else
            return 0;
    
    */
}

int get_front(queue *pq)
{
    return pq->arr[pq->front];
}