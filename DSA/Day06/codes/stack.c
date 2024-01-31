#include"stack.h"

void init_stack(stack *ps)
{
    ps->top = -1;
}

void push(stack *ps,int data)
{
    // increment the top
    ps->top++;
    // insert the data at top position
    ps->arr[ps->top] = data;
}

void pop(stack *ps)
{
    ps->arr[ps->top] = 0;
    ps->top--;
}

int stack_full(stack *ps)
{
    return ps->top == SIZE-1;
}

int stack_empty(stack *ps)
{
    return ps->top == -1;
}

int peek(stack *ps)
{
    return ps->arr[ps->top];
}