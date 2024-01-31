#include"stack.h"

void init_stack(stack_t *st)
{
    st->top = -1;
}

void push(stack_t *st, type_t data)
{
    st->top++;
    st->arr[st->top] = data;
}

type_t pop(stack_t *st)
{
    return st->arr[st->top--];
}

type_t peek(stack_t *st)
{
    return st->arr[st->top];
}

int s_is_empty(stack_t *st)
{
    return st->top == -1;
}

int s_is_full(stack_t *st)
{
    return st->top == SIZE-1;
}