// 2. Create a thread to sort given array of "n" integers using bubble sort. Main thread should print the result after sorting is completed.
// Hint: struct array { int *arr; int size; }
// Pass struct address to thread function (via arg4 of pthread_create()).

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

typedef struct array
{
    int *arr;
    int size;
}arr_t;

#define SWAP(a,b) {int t = a; a = b; b = t;}
void display_arr(arr_t* arr);


void* bubble_sort(void*param)
{
    arr_t *arr = (arr_t *)param;
    for(int it = 0; it < arr->size-1; it++)
    {
        for(int pos = 0; pos < arr->size-1-it; pos++)
        {
            if(arr->arr[pos] > arr->arr[pos+1])
            {
                SWAP(arr->arr[pos],arr->arr[pos+1]);
            }
        }
    }

    return NULL;
}
int main()
{   
    int ret ;
    pthread_t th;
    arr_t arr;
    
    arr.arr = NULL;

    printf("Enter size of array: ");
    scanf("%d",&arr.size);

     arr.arr = (int*)malloc(sizeof(int)* arr.size);
     if(arr.arr == NULL)
     {
        perror("malloc() failed !!");
        _exit(1);
     }

    printf("\nEnter %d elements of array: ",arr.size);
    for(int i = 0; i < arr.size; i++)
    {
        scanf("%d",&arr.arr[i]);
    }

    printf("\nArray before sort :");
    display_arr(&arr);

    ret = pthread_create(&th,NULL,bubble_sort,&arr);
    if(ret < 0)
    {
        perror("pthread_create() failed\n");
        _exit(2);
    }

    printf("main: waiting for thread to complete....\n");

    ret = pthread_join(th, NULL);
    if(ret != 0)
    {
        perror("pthread_join() failed!!\n");
        _exit(3);
    }

    printf("\nArray after sort :");
    display_arr(&arr);

    free(arr.arr);
    arr.arr = NULL;
    return 0;
}

void display_arr(arr_t *arr)
{
    for (int i = 0; i < arr->size; i++)
    {
        printf("%4d", arr->arr[i]);
    }
    printf("\n");

}
