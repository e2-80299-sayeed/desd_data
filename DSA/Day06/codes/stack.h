#define SIZE 30

typedef struct stack
{
    int arr[SIZE];
    int top;
}stack;

int peek(stack *ps);
void init_stack(stack *ps);
void push(stack *ps,int data);
void pop(stack *ps);
int stack_full(stack *ps);
int stack_empty(stack *ps);
