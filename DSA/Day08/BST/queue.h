#ifndef __QUEUE_H
#define __QUEUE_H

#include"bst.h"
#define SIZE 20

typedef node_t * type_t;

// queue type declarations
typedef struct queue
{
	type_t arr[SIZE];
	int front;
	int rear;
}queue_t;

void q_init(queue_t *q);
void q_push(queue_t *q, type_t data);
type_t q_pop(queue_t *q);
type_t q_peek(queue_t *q);

int q_is_full(queue_t *q);
int q_is_empty(queue_t *q);


#endif
