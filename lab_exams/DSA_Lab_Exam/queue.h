#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

typedef struct queue
{
    char name[SIZE];
    int front;
    int rear;
}queue;

void init_queue(queue *Q);
void push(queue *Q, char name[]);
void pop(queue *Q);
char* peek(queue *Q);
void display(queue *Q);
int queue_empty(queue *Q);
int queue_full(queue *Q);