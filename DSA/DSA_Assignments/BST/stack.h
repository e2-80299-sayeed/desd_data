#ifndef __STACK_H
#define __STACK_H

#define SIZE 10

#include "bst.h"

typedef node_t *type_t;

typedef struct stack
{
    type_t arr[SIZE];
    int top;
}stack_t;

void init_stack(stack_t *st);
void push(stack_t *st, type_t data);
type_t pop(stack_t *st);
type_t peek(stack_t *st);
int s_is_empty(stack_t *st);
int s_is_full(stack_t *st);

#endif