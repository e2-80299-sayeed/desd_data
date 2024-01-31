#include<stdio.h>
#include<stdlib.h>
#include"linear_queue.h"


int main()
{
    int choice,data;
    queue Q;
    init_queue(&Q);
do {
    printf("0.Exit\n1.Enqueue\n2.Dequeue\n : \n");
    printf("Enter the choice : \n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 0 : exit(0);
        case 1 : if(queue_full(&Q))
                    printf("Queue is full !!\n");
                else
                {
                    printf("Enter the element to insert : ");
                    scanf("%d",&data);
                    enqueue(&Q,data);
                    printf("Element inserted !\n");
                }
                break;
        case 2 : 
                if(queue_empty(&Q))
                    printf("Q is Empty !\n");
                else 
                {
                    int ele;
                    ele = get_front(&Q);
                    dequeue(&Q);
                    printf("Element Deleted = %d\n",ele);
                }
                break;
        default : 
                printf("Enter the valid choice !\n");
    }   
    }while(choice != 0);
    return 0;
}
