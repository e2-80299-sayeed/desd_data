#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

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



int main()
{
    stack S;
    init_stack(&S);

    int choice;
do{
    printf("\n Enter Your Choice :\n");
    printf("0.Exit\n1.Push\n2.Pop\n3.Peek :\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0 : exit(0);
        case 1: // push
                if(stack_full(&S))
                    printf("Stack is Full !");
                else
                {
                    int data;
                    printf("enter the element to insert :");
                    scanf("%d",&data);
                    push(&S,data);
                    printf("element inserted = %d",data);
                }
                break;
        case 2: // pop
                if(stack_empty(&S))
                    printf("Stack Empty !");
                else
                {
                    int ele = peek(&S);
                    pop(&S);
                    printf("Element popped = %d",ele);
                }
                break;
        case 3: // peek
                if(stack_empty(&S))
                    printf("stack Empty ! Peek not possible !\n");
                else
                {
                    int ele = peek(&S);
                    printf("Topmost element = %d\n",ele);
                }
                break;
        default :   
            printf("enter valid choice !\n");
    }
}while(choice != 0);

    return 0;
}

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