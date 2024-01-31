#include<stdio.h>

#define SIZE 10

typedef struct heap
{
    int arr[SIZE];
    int size;
}heap;

void init_heap(heap *h);
void add_heap(heap *h,int value);
int delete_heap(heap *h);

int main(void)
{
    heap h;
    init_heap(&h);
    int value;

    printf("Enter values : ");
    for(int i = 0; i < 9; i++)
    {
        scanf("%d",&value);
        add_heap(&h,value);
    }

    printf("Heap : ");
    for(int i = 1; i <= 9; i++)
        printf("%-4d",h.arr[i]);

    printf("\n");
    for(int i = 0; i < 9; i++)
        delete_heap(&h);
    
    printf("Heap : ");
    for(int i = 1; i <= 9; i++)
        printf("%-4d",h.arr[i]);

    printf("\n");

    return 0;
}

void init_heap(heap *h)
{
    h->size = 0;
}

void add_heap(heap *h,int value)
{
    h->size++;
    h->arr[h->size] = value;
    
    int pi = h->size / 2;
    int ci = h->size;

    while(pi >= 1)
    {
        if(h->arr[pi] > h->arr[ci])
            break;

        int temp = h->arr[pi];
        h->arr[pi] = h->arr[ci];
        h->arr[ci] = temp;

        ci = pi;
        pi = pi / 2;
    }
}

int delete_heap(heap *h)
{
    int max = h->arr[1];
    h->arr[1] = h->arr[h->size];
    h->arr[h->size] = max;

    h->size--;

    int ci = 1 * 2;

    while(ci <= h->size)
    {
        int pi = ci / 2;
        if(ci + 1 <= h->size && h->arr[ci + 1] > h->arr[ci])
            ci =  ci + 1;
        
        if(h->arr[pi] > h->arr[ci])
            break;
        
        int temp = h->arr[ci];
        h->arr[ci] = h->arr[pi];
        h->arr[pi] = temp;
    
        ci = ci * 2;
    }
    return max;
}