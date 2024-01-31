#ifndef __HEAP_H
#define __HEAP_H

#include<stdio.h>

#define SIZE 10

typedef struct heap
{
    int arr[SIZE];
    int size;
}heap_t;

void init_heap(heap_t *h);
void add_heap(heap_t *h, int value);
int delete_heap(heap_t *h);

#endif