#include"heap.h"

void init_heap(heap_t *h)
{
    h->size = 0;
}

void add_heap(heap_t *h, int value)
{
    //1. increament size of heap by 1
    h->size++;
    //2. add value at first(size) empty location of array
    h->arr[h->size] = value;
    //3. find parent of newly added element
    int pi = h->size / 2;
    int ci = h->size;
    //4. compare newly added value with all its ancestors
    while(pi >= 1)
    {
        //5. if parent is greater than child, then stop
        if(h->arr[pi] > h->arr[ci])
            break;
        //6. if child is greater than parent, then swap parent and child
        int temp =  h->arr[pi];
        h->arr[pi] = h->arr[ci];
        h->arr[ci] = temp;
        //7. update child and parent index
        ci  = pi;
        pi = pi / 2;
    }
}

int delete_heap(heap_t *h)
{
    //1. swap first and last element of heap
    int max = h->arr[1];
    h->arr[1] = h->arr[h->size];
    h->arr[h->size] = max;
    //2. decreaement size of heap by one
    h->size--;
    //3. find index of child
    int ci = 1 * 2;
    //4. compare element with both of its childs untill leaf node
    while(ci <= h->size)
    {
        //5. find index of parent
        int pi = ci / 2;
        //6. find maximum child of pi index element
        if(ci + 1 <= h->size && h->arr[ci + 1] > h->arr[ci])
            ci = ci + 1;
        //7. if parent is greater than maximum child, then stop
        if(h->arr[pi] > h->arr[ci])
            break;
        //8. if maximum child is greater than parent, then swap parent and maximum child
        int temp = h->arr[ci];
        h->arr[ci] = h->arr[pi];
        h->arr[pi] = temp;
        //9. update child index
        ci = ci * 2;
    }
    //10. return maximum element
    return max;
}