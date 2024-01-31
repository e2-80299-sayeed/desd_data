#include"linear_queue.h"

void init_queue(queue *pq)
{
    pq->rear = -1;
    pq->front = -1;
}

void enqueue(queue *pq, int data)
{
    pq->rear++;
    pq->arr[pq->rear] = data;

    if(pq->front == -1)
        pq->front = 0;
}

void dequeue(queue *pq)
{
    pq->arr[pq->front] = 0;

    pq->front++;
}

int queue_empty(queue *pq)
{
    return (pq->rear == -1 || pq->front > pq->rear);
}

int queue_full(queue *pq)
{
    return (pq->rear == SIZE -1);
}

int get_front(queue *pq)
{
    return (pq->arr[pq->front]);
}