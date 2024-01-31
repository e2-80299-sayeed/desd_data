#include"heap.h"

heap_t pri_queue; // global variable for queue

void init_queue(void);
void push(int value);
int pop(void);
int peek(void);
int is_empty(void);
int is_full(void);


int main(void)
{
    init_queue();

    push(6);
    push(14);
    push(3);

    printf("peeked element = %d\n", peek());    // 14
    printf("poped element = %d\n", pop());      // 14
    printf("peeked element = %d\n", peek());    // 6

    return 0;
}
void init_queue(void)
{
    init_heap(&pri_queue);
}
void push(int value)
{
    add_heap(&pri_queue, value);
}
int pop(void)
{
    return delete_heap(&pri_queue);
}
int peek(void)
{
    return pri_queue.arr[1];
}
int is_empty(void)
{
    return pri_queue.size == 0;
}
int is_full(void)
{
    return pri_queue.size == SIZE - 1;
}
