#include"queue.h"

void q_init(queue_t *q)
{
    q->front = q->rear = -1;
}

void q_push(queue_t *q, type_t data)
{
    q->rear++;
    q->arr[q->rear] = data;
}

type_t q_pop(queue_t *q)
{
    return q->arr[++q->front];
}

type_t q_peek(queue_t *q)
{
    return q->arr[q->front + 1];
}

int q_is_full(queue_t *q)
{
    return q->rear == SIZE1 - 1;
}

int q_is_empty(queue_t *q)
{
    return q->front == q->rear;
}