#include"queue.h"

void q_init(queue_t *q)
{
	// initialize front and rear equal to -1
	q->front = q->rear = -1;
}
void q_push(queue_t *q, type_t data)
{
	//1. repostition rear (inc)
	q->rear++;
	//2. add data at rear index
	q->arr[q->rear] = data;
}
type_t q_pop(queue_t *q)
{
	//1. reposition front (inc)
	return q->arr[++q->front];
}
type_t q_peek(queue_t *q)
{
	//2. read data of front + 1 index
	return q->arr[q->front + 1];
}

int q_is_full(queue_t *q)
{
	return q->rear == SIZE - 1;
}
int q_is_empty(queue_t *q)
{
	return q->front == q->rear;
}








